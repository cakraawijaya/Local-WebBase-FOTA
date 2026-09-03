[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL-%2D3.0-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/license/gpl-3.0)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Local-WebBase-FOTA?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-ESP32-light.svg?style=flat&logo=espressif&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-BNSP%20IIoT%20Project-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Local WebBase FOTA
Web-based IoT monitoring, control, and firmware management system — monitors temperature and humidity, enables remote lamp control, provides authenticated web access, CSV data export, and enables wireless firmware updates over a local network.

<br><br>

## Project Requirements
| Part | Description |
| --- | --- |
| Development Board | DOIT ESP32 DEVKIT V1 |
| Code Editor | Arduino IDE 1.8.19 (Stable Legacy Version) |
| Driver | CP210X USB Driver |
| Communications Protocol | Hypertext Transfer Protocol (HTTP) |
| IoT Architecture | 3 Layer |
| Programming Language | C/C++ |
| Arduino Library | • WiFi (default)<br>• WiFiClient (default)<br>• WebServer (default)<br>• ESPmDNS (default)<br>• Update (default)<br>• WiFiUdp (default)<br>• DHT sensor library by Adafruit (Version: 1.4.6)<br>• NTPClient by Fabrice Weinberg (Version: 3.2.1) |
| Actuators | • LED (x1)<br>• Electromechanical relay 2-channel (x1) |
| Sensor | DHT11: Air Temperature & Humidity (x1) |
| Other Components | • Micro USB cable - USB type A (x1)<br>• ESP32 expansion board (x1)<br>• Breadboard (x1)<br>• Adaptor DC 9V 1A (x1)<br>• Resistor 220 ohm (x1)<br>• Jumper cable (1 set) |

<br><br>

## Download & Install
1. Arduino IDE

   <table><tr><td width="810">

   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. CP210X USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CP210X_USBdriver
   ```

   </td></tr></table>
   
<br><br>

## Project Designs

<table>
<tr>
<th width="280">Architecture</th>
<th width="280">Pictorial Diagram</th>
<th width="280">Block Diagram</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Architecture.jpg" alt="architecture"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Wiring</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Arduino IDE Setup for Firmware Init
1. Open the ``` Arduino IDE ``` first, then open the project by clicking ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
      
      ``` Config_OTA.ino ```

   </td></tr></table><br>
   
2. Fill in the ``` Additional Board Manager URLs ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` File ``` -> ``` Preferences ``` -> enter the ``` Boards Manager Url ``` by copying the following link :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```

   </td></tr></table><br>
   
3. ``` Board Setup ``` in Arduino IDE

   <table>
      <tr><th width="810">

      How to setup the ``` DOIT ESP32 DEVKIT V1 ``` board
            
      </th></tr>
      <tr><td width="810">
         
      • Click ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Install ``` esp32 ```.
   
      • Then selecting a board by clicking: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Change the Board Speed ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```

   </td></tr></table><br>
   
5. ``` Install Library ``` in Arduino IDE

   <table><tr><td width="810">
         
      Download all the library zip files. Then paste it in the: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

6. ``` Port Setup ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` Port ``` -> Choose according to your device port ``` (you can see in device manager) ```

   </td></tr></table><br>

7. Change the ``` WiFi Name ```, ``` WiFi Password ```, and so on according to what you are currently using.<br><br>

8. Before uploading the program, please click: ``` Verify ```.<br><br>

9. If there is no error in the program code, then please click: ``` Upload ```.<br><br>
    
10. Some things you need to do when using the ``` ESP32 board ``` :

    <table><tr><td width="810">
       
       • If ``` ESP32 board ``` cannot process ``` Source Code ``` totally -> Press ``` EN (RST) ``` button -> ``` Restart ```.

       • If ``` ESP32 board ``` cannot process ``` Source Code ``` automatically then :<br>

      - When information: ``` Uploading... ``` has appeared -> immediately press and hold the ``` BOOT ``` button.<br>

      - When information: ``` Writing at .... (%) ``` has appeared -> release the ``` BOOT ``` button.

      • If message: ``` Done Uploading ``` has appeared -> ``` The previously entered program can already be operated ```.

      • Do not press the ``` BOOT ``` and ``` EN ``` buttons at the same time as this may switch to ``` Upload Firmware ``` mode.

    </td></tr></table><br>

11. If there is still a problem when uploading the program, then try checking the ``` driver ``` / ``` port ``` / ``` others ``` section.

<br><br>

## Arduino IDE Setup for Binary Compilation
1. Open the ``` Arduino IDE ``` first, then open the project by clicking ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
      
      • ``` LED_Blink_OTA.ino ```

      • ``` Monitoring_Controlling_Device_OTA.ino ```

   </td></tr></table><br>
   
2. Fill in the ``` Additional Board Manager URLs ``` in Arduino IDE

   <table><tr><td width="810">
         
      Click ``` File ``` -> ``` Preferences ``` -> enter the ``` Boards Manager Url ``` by copying the following link :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```

   </td></tr></table><br>
   
3. ``` Board Setup ``` in Arduino IDE

   <table>
      <tr><th width="810">

      How to setup the ``` DOIT ESP32 DEVKIT V1 ``` board
            
      </th></tr>
      <tr><td width="810">
         
      • Click ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Install ``` esp32 ```.
   
      • Then selecting a board by clicking: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Install Library ``` in Arduino IDE

   <table><tr><td width="810">
         
      Download all the library zip files. Then paste it in the: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

5. Change the ``` WiFi Name ```, ``` WiFi Password ```, and so on according to what you are currently using.<br><br>

6. Next, select ``` Sketch ``` -> ``` Export Compiled Binary ```.<br><br>

7. Wait until the process is complete, the resulting binary file (.bin) is then ready to be used for the OTA process.

<br><br>

## Over-The-Air (FOTA) Firmware Update Setup
1. Please log in first via the ``` Local Web Server ```.

   <table><tr><td width="810">
      
      • Username: ``` admin ```

      • Password: ``` admin ```
         
   </td></tr></table><br>
   
2. Upload the binary files (.bin) one at a time to identify the differences between each firmware update version.

   <table><tr><td width="810">

      • ``` LED_Blink_OTA.bin ```

      • ``` Monitoring_Controlling_Device_OTA.bin ```
         
   </td></tr></table>

<br><br>

## Get Started
1. Download and extract this repository.<br><br>
    
2. Make sure you have the necessary electronic components.<br><br>
   
3. Make sure your components are designed according to the diagram.<br><br>
      
4. Configure your device according to the settings above.<br><br> 
 
5. Please enjoy [Done].

<br><br>

## Highlights

<table>
<tr>
<th width="840" colspan="4">Login Web Server</th>
</tr>
<tr>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Login (Initial Firmware).jpg" alt="login-firmware-init"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Invalid Login (Initial Firmware).jpg" alt="invalid-login-firmware-init"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Login (Controlling-Monitoring Device).jpg" alt="login-controlling-monitoring-device"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Invalid Login (Controlling-Monitoring Device).jpg" alt="invalid-login-controlling-monitoring-device"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Web Server Dashboard</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Dashboard.jpg" alt="dashboard"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="4">LED Control</th>
</tr>
<tr>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Alert LED ON.jpg" alt="alert-led-on"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Device (LED ON).jpg" alt="led-on"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Alert LED OFF.jpg" alt="alert-led-off"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/Device (LED OFF).jpg" alt="led-off"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Initial Firmware Flashing</th>
<th width="420">FOTA</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Initial Firmware Flashing.jpg" alt="initial-firmware-flashing"></td>
<td align="center"><img src="Assets/Documentation/Experiment/FOTA.jpg" alt="fota"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Download CSV</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Download CSV.jpg" alt="download-csv"></td>
</tr>
</table>

<br>
<strong>More information:</strong> <a href="https://github.com/cakraawijaya/Local-WebBase-FOTA/blob/master/Assets/Documentation/Report/Portofolio%20Pelatihan%20Sertifikasi%20BNSP%20IIoT%20-%20Devan%20Cakra%20Mudra%20Wijaya-36-48.pdf"><u>Click Here</u></a>

<br><br>

## Appreciation
If this work is useful to you, then support this work as a form of appreciation to the author by clicking the ``` ⭐Star ``` button at the top of the repository.

<br><br>

## Disclaimer
This application is the result of the development of the Edutic.id x BNSP Bootcamp 2026. I do not deny that I still use third-party services in this work, including: libraries, frameworks, and so on.
