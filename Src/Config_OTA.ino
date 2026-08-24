#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);


String login_page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Login</title>
  
  <link rel="stylesheet"
  href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css">


  <style>
    * {
      box-sizing: border-box;
    }
    
    body {
      margin: 0;
      padding: 20px;
      min-height: 100vh;
      display: flex;
      justify-content: center;
      align-items: center;
      font-family: Arial, Helvetica, sans-serif;
      background: linear-gradient(135deg, #667eea, #764ba2, #f093fb);
    }
    
    form {
      width: 100%;
      max-width: 350px;
      padding: 35px 30px;
      text-align: center;
      background: rgba(255,255,255,0.96);
      border-radius: 20px;
      box-shadow: 0 20px 50px rgba(0,0,0,0.25);
    }
    
    h1 {
      margin: 0 0 25px;
      color: #4a4a4a;
      font-size: 28px;
    }
    
    h1 i {
      color: #667eea;
      margin-right: 8px;
    }
    
    input {
      width: 100%;
      height: 46px;
      margin: 8px 0;
      padding: 0 15px;
      border: 2px solid transparent;
      border-radius: 10px;
      outline: none;
      background: #f5f5f7;
      font-size: 15px;
    }
    
    input:focus {
      background: #fff;
      border-color: #667eea;
      box-shadow: 0 0 0 3px rgba(102,126,234,0.15);
    }
    
    .btn {
      color: white;
      background: linear-gradient(135deg, #667eea, #764ba2);
      border: none;
      cursor: pointer;
      font-weight: bold;
      transition: 0.3s;
    }
    
    .btn:hover {
      transform: translateY(-2px);
      box-shadow: 0 8px 20px rgba(102,126,234,0.4);
    }
  </style>

</head>

<body>

  <form name="loginForm" onsubmit="return check(this)">
    <h1>
      <i class="fa-solid fa-microchip"></i>
      ESP32 Login
    </h1>
  
    <input name="userid" placeholder="User ID"
      autocomplete="username">
  
    <input
      name="pwd" placeholder="Password" type="password"
      autocomplete="current-password">
  
    <input type="submit" class="btn" value="Login"
    >
  </form>

  <script>
    function check(form) {
    
      if (
        form.userid.value === 'admin' &&
        form.pwd.value === 'admin'
      ) {
    
        window.location.href = '/serverIndex';
        return false;
    
      } else {
    
        alert('Error: Invalid Username or Password');
        return false;
    
      }
    }
  </script>

</body>
</html>
)rawliteral";


String main_page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>

  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  
  <title>ESP32 Firmware Update</title>
  
  <link rel="stylesheet"
  href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css">


  <style>
    
    * {
      box-sizing: border-box;
    }
    
    body {
      margin: 0;
      padding: 20px;
      min-height: 100vh;
    
      display: flex;
      justify-content: center;
      align-items: center;
    
      font-family: Arial, Helvetica, sans-serif;
    
      background: linear-gradient(
        135deg,
        #667eea,
        #764ba2,
        #f093fb
      );
    }
    
    form {
      width: 100%;
      max-width: 600px;
      padding: 35px 40px;
      text-align: center;
      background: rgba(255,255,255,0.96);
      border-radius: 25px;
      box-shadow: 0 20px 50px rgba(0,0,0,0.25);
    }
    
    h1 {
      margin: 0 0 8px;
      color: #4a4a4a;
      font-size: 36px;
    }
    
    h1 i {
      margin-right: 10px;
      color: #667eea;
    }
    
    .subtitle {
      margin-bottom: 28px;
      color: #888;
      font-size: 18px;
    }
    
    #file-input {
      width: 100%;
      min-height: 65px;
      margin: 0 auto 15px;
      padding: 12px 18px;
      display: flex;
      align-items: center;
      justify-content: center;
      gap: 10px;
      border: 3px dashed #b5b5c3;
      border-radius: 15px;
      background: #f8f8fa;
      color: #777;
      text-align: center;
      cursor: pointer;
      transition: 0.3s;
      overflow: hidden;
    }
    
    #file-input:hover {
      border-color: #667eea;
      background: #f2f3ff;
      color: #667eea;
    }
    
    #file-input i {
      flex-shrink: 0;
      color: #667eea;
      font-size: 20px;
    }
    
    #file-name {
      max-width: 100%;
      text-align: center;
      line-height: 1.4;
      white-space: normal;
      overflow-wrap: anywhere;
      word-break: break-word;
    }
    
    .btn {
      width: 100%;
      height: 55px;
      margin-top: 5px;
      border: none;
      border-radius: 13px;
      color: white;
    
      background:
        linear-gradient(
          135deg,
          #667eea,
          #764ba2
        );
    
      font-size: 18px;
      font-weight: bold;
      cursor: pointer;
      transition: 0.3s;
    }
    
    .btn:hover {
      transform: translateY(-2px);
    
      box-shadow:
        0 8px 20px
        rgba(102,126,234,0.4);
    }
    
    .btn:disabled {
      opacity: 0.6;
      cursor: not-allowed;
      transform: none;
      box-shadow: none;
    }
    
    #prg {
      min-height: 24px;
      margin-top: 62px;
      color: #667eea;
      font-size: 15px;
      font-weight: bold;
      line-height: 1.5;
    }
    
    #prgbar {
      width: 100%;
      height: 12px;
      margin-top: 8px;
      overflow: hidden;
      border-radius: 20px;
      background: #eeeeee;
    }
    
    #bar {
      width: 0%;
      height: 100%;
      border-radius: 20px;
    
      background:
        linear-gradient(
          90deg,
          #667eea,
          #764ba2,
          #f093fb
        );
    
      transition: width 0.2s ease;
    }
    
    .footer {
      margin-top: 25px;
      color: #999;
      font-size: 14px;
    }
    
    .footer i {
      margin-right: 6px;
    }
    
    @media (max-width: 600px) {
      form {
        padding: 28px 20px;
        border-radius: 20px;
      }
    
      h1 {
        font-size: 28px;
      }
    
      .subtitle {
        font-size: 15px;
        margin-bottom: 22px;
      }
    
      #file-input {
        font-size: 14px;
      }
    
      .btn {
        height: 52px;
        font-size: 17px;
      }
    }
  </style>

</head>
<body>

  <form method="POST" action="#"
    enctype="multipart/form-data"
    id="upload_form">
  
    <h1>
      <i class="fa-solid fa-microchip"></i>
      ESP32 Update
    </h1>
  
    <div class="subtitle">
      Firmware Over-The-Air Update
    </div>
  
    <input type="file" name="update"
      id="file" onchange="sub(this)"
      style="display:none">
  
    <label id="file-input" for="file">
      <i class="fa-solid fa-file-arrow-up"></i>
      <span id="file-name">
        Choose firmware file...
      </span>
    </label>
  
    <input type="submit" class="btn" id="update-btn" value="Update">
    <div id="prg"></div>
  
    <div id="prgbar">
      <div id="bar"></div>
    </div>
  
    <div class="footer">
      <i class="fa-solid fa-wifi"></i>
      ESP32 OTA Firmware Update
    </div>
  </form>
  
  
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
  
  <script>
  
  
  function sub(obj) {
  
    var fileName = obj.value.split('\\');
  
    var selectedFile = fileName[fileName.length - 1];
  
    document.getElementById(
      'file-name'
    ).innerText =
      selectedFile || 'Choose firmware file...';
  
  }
  
  
  $('#upload_form').submit(function(e) {
  
    e.preventDefault();
  
    var fileInput = document.getElementById('file');
  
    if (!fileInput.files || fileInput.files.length === 0) {
  
      $('#prg').html(
        '<i class="fa-solid fa-circle-exclamation"></i> ' +
        'Silakan pilih file firmware terlebih dahulu!'
      );
  
      return;
    }
  
    var form = $('#upload_form')[0];
  
    var data = new FormData(form);
  
    $('#update-btn').prop('disabled', true).val('Uploading...');
  
    $('#prg').html('<i class="fa-solid fa-spinner fa-spin"></i> ' + 'Uploading: 0%');
  
    $('#bar').css('width', '0%');
  
  
    $.ajax({
      url: '/update',
      type: 'POST',
      data: data,
      contentType: false,
      processData: false,
  
      xhr: function() {
        var xhr = new window.XMLHttpRequest();
  
        xhr.upload.addEventListener('progress', function(evt) {
            if (evt.lengthComputable) {
  
              var progress = Math.round((evt.loaded / evt.total) * 100);
  
              $('#prg').html(
                '<i class="fa-solid fa-spinner fa-spin"></i> ' +
                'Uploading: ' + progress + '%'
              );
  
              $('#bar').css('width', progress + '%');
  
            }
          },
  
          false
        );
  
        return xhr;
      },
  
      success: function(response) {
        var result = String(response).trim().toUpperCase();
  
        $('#bar').css('width', '100%');
  
        if (result === 'OK') {
  
          $('#prg').html(
            '<i class="fa-solid fa-circle-check"></i> ' +
            'Update Berhasil! ESP32 akan restart...'
          );
  
          $('#update-btn')
            .val('Update Berhasil');

          setTimeout(function() {
            window.location.href = '/';
          }, 2000);
        }
  
        else {
  
          $('#prg').html(
            '<i class="fa-solid fa-circle-xmark"></i> ' +
            'Update Gagal!'
          );
  
          $('#update-btn').prop('disabled', false).val('Update');
  
        }
      },
  
      error: function(xhr, status, error) {
        if (xhr.status >= 400) {
  
          $('#prg').html(
            '<i class="fa-solid fa-circle-xmark"></i> ' +
            'Update Gagal!'
          );
  
          $('#update-btn').prop('disabled', false).val('Update');
  
        } else {
  
          $('#prg').html(
            '<i class="fa-solid fa-circle-check"></i> ' +
            'Update Berhasil! ESP32 sedang restart...'
          );
  
          $('#bar').css('width', '100%');
  
        }
      }
    });
  });

</script>

</body>
</html>
)rawliteral";


void setup(void) {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (!MDNS.begin("esp32")) {
    Serial.println("Error setting up mDNS responder!");
    while (1) { delay(1000); }
  }

  Serial.println("mDNS responder started");

  server.on("/", HTTP_GET, []() {
      server.sendHeader(
        "Connection",
        "close"
      );

      server.send(
        200,
        "text/html",
        login_page
      );
  });

  server.on("/serverIndex", HTTP_GET, []() {
      server.sendHeader(
        "Connection",
        "close"
      );

      server.send(
        200,
        "text/html",
        main_page
      );
    }
  );

  server.on("/update", HTTP_POST, []() {
      bool updateSuccess = !Update.hasError();
      Serial.println();
      Serial.println("================================");

      if (updateSuccess) {
        Serial.println("OTA UPDATE SUCCESS");
      }

      else {
        Serial.println("OTA UPDATE FAILED");
      }

      Serial.println("================================");
      server.sendHeader("Connection", "close");

      if (updateSuccess) {
        server.send(
          200,
          "text/plain",
          "OK"
        );

        delay(1500);
        Serial.println("Restarting ESP32...");
        ESP.restart();
      }

      else {
        server.send(
          500,
          "text/plain",
          "FAIL"
        );
      }
    },

    []() {
      HTTPUpload& upload = server.upload();
      
      if (upload.status == UPLOAD_FILE_START) {
        Serial.printf(
          "Update Start: %s\n",
          upload.filename.c_str()
        );

        if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {
          Serial.println("Update.begin() FAILED!");

          Update.printError(Serial);
        }

        else {
          Serial.println("Update.begin() OK");
        }
      }

      else if (upload.status == UPLOAD_FILE_WRITE) {
        size_t written =
          Update.write(upload.buf, upload.currentSize);

        if (written != upload.currentSize) {
          Serial.println(
            "Update.write() FAILED!"
          );

          Update.printError(Serial);
        }
      }

      else if (upload.status == UPLOAD_FILE_END) {
        Serial.printf(
          "Upload finished. Total size: %u bytes\n",
          upload.totalSize
        );

        if (Update.end(true)) {
          Serial.printf(
            "Update Success: %u bytes\n",
            upload.totalSize
          );
        }

        else {
          Serial.println("Update.end() FAILED!");
          Update.printError(Serial);
        }
      }

      else if (upload.status == UPLOAD_FILE_ABORTED) {
        Serial.println("OTA Upload Aborted!");
        Update.abort();
      }
    }
  );

  server.begin();
  Serial.println("HTTP server started");
}


void loop(void) {
  server.handleClient();
  delay(2);
}
