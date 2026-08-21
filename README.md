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
| Arduino Library | • WiFi (default)<br>• DHT sensor library by Adafruit (Version: 1.4.6)<br>• Arduino_ESP32_OTA by Arduino (Version: 0.3.1)<br>• NTPClient by Fabrice Weinberg (Version: 3.2.1)<br>• WiFiManager by tablatronix (Version: 2.0.17)<br>• WiFiWebServer by Khoi Hoang (Version: 1.10.1) |
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
<th width="840">Block Diagram</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Architecture</th>
<th width="420">Pictorial Diagram</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Diagram/Architecture.jpg" alt="architecture"></td>
<td><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Wiring</th>
</tr>
<tr>
<td><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Get Started
1. Download and extract this repository.<br><br>
    
2. Make sure you have the necessary electronic components.<br><br>
   
3. Make sure your components are designed according to the diagram.<br><br>
      
4. Configure your device according to the settings above.<br><br> 
 
5. Please enjoy [Done].

<br><br>

## Appreciation
If this work is useful to you, then support this work as a form of appreciation to the author by clicking the ``` ⭐Star ``` button at the top of the repository.

<br><br>

## Disclaimer
This application is the result of the development of the Edutic.id x BNSP Bootcamp 2026. I do not deny that I still use third-party services in this work, including: libraries, frameworks, and so on.