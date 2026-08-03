#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <DHT.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Konfigurasi WiFi
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Konfigurasi Relay
const int Relay1 = 13;

// Relay Active LOW
int relayState = HIGH;

// Konfigurasi sensor DHT11
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float temperature = 0.0;
float humidity = 0.0;

// Konfigurasi server
WebServer server(80);

// Konfigurasi NTP Client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "id.pool.ntp.org", 25200, 60000); // UTC+7 ( Waktu Indonesia Barat )

// Data logger
String dataLog = "Timestamp,Temperature,Humidity\n";

// Halaman login
String loginPage =
  R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Login</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css">
  <style>body {background-color: #f8f9fa; text-align: center; font-family: Arial;}</style>
</head>
<body>
  <div class="container">
    <h1 class="text-primary mt-4">ESP32 Login</h1>
    <form onsubmit="checkLogin(event)">
      <input id="userid" class="form-control my-2" placeholder="Username" required>
      <input id="pwd" type="password" class="form-control my-2" placeholder="Password" required>
      <button class="btn btn-primary w-100">Login</button>
    </form>
  </div>
  <script>
    function checkLogin(event) {
      event.preventDefault();
      const user = document.getElementById('userid').value;
      const pass = document.getElementById('pwd').value;
      if (user === 'admin' && pass === 'admin') {
        window.location.href = '/control';
      } else {
        alert('Invalid username or password!');
      }
    }
  </script>
</body>
</html>
)rawliteral";

// Halaman kontrol LED dan sensor
String controlPage() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Control</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">
  <style>
    body {
      background: #f4f6f9;
      font-family: 'Arial', sans-serif;
    }
    .card {
      border-radius: 15px;
    }
    #alertBox {
      display: none;
      position: fixed;
      top: 20px;
      right: 20px;
      z-index: 9999;
    }
    #log {
      margin-top: 20px;
    }
    table {
      width: 100%;
      margin-top: 20px;
      border-collapse: collapse;
    }
    th, td {
      border: 1px solid #ddd;
      text-align: center;
      padding: 8px;
    }
    th {
      background-color: #f2f2f2;
    }
  </style>
</head>
<body>
  <div class="container py-5">
    <h1 class="text-center text-primary mb-4"><i class="fas fa-laptop-house"></i> ESP32 Control</h1>

    <div class="text-center mb-4">
      <button class="btn btn-success btn-lg" onclick="toggleLed()"><i class="fas fa-lightbulb"></i> Toggle LED</button>
    </div>

    <div class="row">
      <div class="col-md-6">
        <div class="card shadow-sm text-center p-4">
          <h2><i class="fas fa-temperature-high text-danger"></i> Temperature</h2>
          <p id="temperature" class="display-5 text-primary">-- °C</p>
        </div>
      </div>
      <div class="col-md-6">
        <div class="card shadow-sm text-center p-4">
          <h2><i class="fas fa-tint text-info"></i> Humidity</h2>
          <p id="humidity" class="display-5 text-primary">-- %</p>
        </div>
      </div>
    </div>

    <div class="text-center mt-4">
      <a href="/serverIndex" class="btn btn-warning btn-lg"><i class="fas fa-upload"></i> Firmware Update</a>
      <a href="/downloadLog" class="btn btn-secondary btn-lg"><i class="fas fa-file-download"></i> Download CSV</a>
    </div>

    <canvas id="chart" width="400" height="200" class="mt-4"></canvas>

    <table>
      <thead>
        <tr>
          <th>Timestamp</th>
          <th>Temperature (°C)</th>
          <th>Humidity (%)</th>
        </tr>
      </thead>
      <tbody id="dataLogTable"></tbody>
    </table>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <script>
    function toggleLed() {
      fetch('/toggleLed').then(response => response.text()).then(message => {
        alert(message);
      });
    }

    function updateSensors() {
      fetch('/sensorData').then(response => response.json()).then(data => {
        document.getElementById('temperature').textContent = data.temperature + ' °C';
        document.getElementById('humidity').textContent = data.humidity + ' %';
        addToChart(data.temperature, data.humidity);
        updateTable(data.timestamp, data.temperature, data.humidity);
      });
    }

    function addToChart(temp, hum) {
      const now = new Date().toLocaleTimeString();
      chart.data.labels.push(now);
      chart.data.datasets[0].data.push(temp);
      chart.data.datasets[1].data.push(hum);
      chart.update();
    }

    function updateTable(timestamp, temp, hum) {
      const table = document.getElementById('dataLogTable');
      const row = `<tr><td>${timestamp}</td><td>${temp}</td><td>${hum}</td></tr>`;
      table.innerHTML += row;
    }

    const ctx = document.getElementById('chart').getContext('2d');
    const chart = new Chart(ctx, {
      type: 'line',
      data: {
        labels: [],
        datasets: [
          {
            label: 'Temperature (°C)',
            borderColor: 'red',
            data: [],
          },
          {
            label: 'Humidity (%)',
            borderColor: 'blue',
            data: [],
          }
        ]
      }
    });

    setInterval(updateSensors, 5000);
  </script>
</body>
</html>
)rawliteral";
  return html;
}

// Halaman firmware update
String serverIndex = 
R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>OTA Update</title>
  <style>
    body {font-family: Arial; text-align: center; margin-top: 50px;}
    #bar {background: #3498db; height: 10px; width: 0%; margin-top: 20px;}
  </style>
</head>
<body>
  <h1>Update Firmware</h1>
  <form method="POST" enctype="multipart/form-data" id="upload_form">
    <input type="file" name="update">
    <input type="submit" value="Update">
  </form>
  <div id="bar"></div>
  <script>
    document.getElementById('upload_form').onsubmit = function(e) {
      e.preventDefault();
      const form = new FormData(this);
      const xhr = new XMLHttpRequest();
      xhr.open("POST", "/update");
      xhr.upload.onprogress = function(event) {
        const percent = Math.round((event.loaded / event.total) * 100);
        document.getElementById('bar').style.width = percent + '%';
      };
      xhr.onload = function() {
        alert(xhr.responseText);
        if (xhr.responseText === 'OK') location.reload();
      };
      xhr.send(form);
    };
  </script>
</body>
</html>
)rawliteral";

// Setup
void setup() {
  Serial.begin(115200);
  pinMode(Relay1, OUTPUT);

  // Relay OFF saat ESP32 mulai
  digitalWrite(Relay1, HIGH);
  relayState = HIGH;

  dht.begin();
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  
  timeClient.begin();

  server.on("/", HTTP_GET, []() { server.send(200, "text/html", loginPage); });
  
  server.on("/control", HTTP_GET, []() { server.send(200, "text/html", controlPage()); });

  server.on("/toggleLed", HTTP_GET, []() {
    relayState = !relayState;
    digitalWrite(Relay1, relayState);
    if (relayState == HIGH) {
      server.send(200, "text/plain", "LED OFF");
    } else {
      server.send(200, "text/plain", "LED ON");
    }
  });
  
  server.on("/sensorData", HTTP_GET, []() {
    timeClient.update();
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    String timeStamp = timeClient.getFormattedTime();
    dataLog += timeStamp + "," + String(temperature) + "," + String(humidity) + "\n";
    String json = "{\"timestamp\":\"" + timeStamp + "\",\"temperature\":\"" + String(temperature) + "\",\"humidity\":\"" + String(humidity) + "\"}";
    server.send(200, "application/json", json);
  });
  
  server.on("/downloadLog", HTTP_GET, []() {
    server.send(200, "text/csv", dataLog);
  });
  
  server.on("/serverIndex", HTTP_GET, []() { server.send(200, "text/html", serverIndex); });
  
  server.on("/update", HTTP_POST, []() {
    server.send(200, "text/plain", Update.hasError() ? "FAIL" : "OK");
    ESP.restart();
  }, []() {
    HTTPUpload& upload = server.upload();
    if (upload.status == UPLOAD_FILE_START) Update.begin(UPDATE_SIZE_UNKNOWN);
    else if (upload.status == UPLOAD_FILE_WRITE) Update.write(upload.buf, upload.currentSize);
    else if (upload.status == UPLOAD_FILE_END) Update.end(true);
  });
  
  server.begin();
  Serial.println("HTTP server started");
}

// Loop
void loop() {
  server.handleClient();
}
