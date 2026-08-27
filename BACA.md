[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL-%2D3.0-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/license/gpl-3.0)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Local-WebBase-FOTA?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-ESP32-light.svg?style=flat&logo=espressif&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-BNSP%20IIoT%20Project-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Local WebBase FOTA
Sistem pemantauan, pengendalian, dan pengelolaan firmware IoT berbasis web — memantau suhu dan kelembapan, memungkinkan pengendalian lampu dari jarak jauh, menyediakan akses web yang terotentikasi, ekspor data dalam format CSV, serta memungkinkan pembaruan firmware nirkabel melalui jaringan lokal.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | DOIT ESP32 DEVKIT V1 |
| Editor Kode | Arduino IDE 1.8.19 (Versi Lama yang Stabil) |
| Driver | CP210X USB Driver |
| Protokol Komunikasi | Hypertext Transfer Protocol (HTTP) |
| Arsitektur IoT | 3 Lapisan |
| Bahasa Pemrograman | C/C++ |
| Pustaka Arduino | • WiFi (bawaan)<br>• DHT sensor library oleh Adafruit (Versi: 1.4.6)<br>• Arduino_ESP32_OTA oleh Arduino (Versi: 0.3.1)<br>• NTPClient oleh Fabrice Weinberg (Versi: 3.2.1)<br>• WiFiManager oleh tablatronix (Versi: 2.0.17)<br>• WiFiWebServer oleh Khoi Hoang (Versi: 1.10.1) |
| Aktuator | • LED (x1)<br>• Relay elektromekanis 2-channel (x1) |
| Sensor | DHT11: Suhu & Kelembapan Udara (x1) |
| Komponen Lainnya| • Kabel USB Mikro - USB tipe A (x1)<br>• Papan ekspansi ESP32 (x1)<br>• Breadboard (x1)<br>• Adaptor DC 9V 1A (x1)<br>• Resistor 220 ohm (x1)<br>• Kabel jumper (1 set) |

<br><br>

## Unduh & Instal
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

## Rancangan Proyek

<table>
<tr>
<th width="280">Arsitektur</th>
<th width="280">Diagram Ilustrasi</th>
<th width="280">Diagram Blok</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Architecture.jpg" alt="architecture"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Pengkabelan</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE untuk Firmware Inisialisasi
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
      
      ``` Config_OTA.ino ```
         
   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```
         
   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` DOIT ESP32 DEVKIT V1 ```
            
      </th></tr>
      <tr><td width="810">
         
      • Klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp32 ```.

      • Kemudian pilih papan dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```
         
   </td></tr></table><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">

      Unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```
         
   </td></tr></table><br>

6. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Port ``` -> Pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```
         
   </td></tr></table><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.<br><br>
    
10. Beberapa hal yang perlu anda lakukan saat menggunakan ``` board ESP32 ``` :

    <table><tr><td width="810">
       
       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara total -> Tekan tombol ``` EN (RST) ``` -> ``` Restart ```.

       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara otomatis maka :<br>

      - Ketika informasi: ``` Uploading... ``` telah muncul -> segera tekan dan tahan tombol ``` BOOT ```.<br>

      - Ketika informasi: ``` Writing at .... (%) ``` telah muncul -> lepaskan tombol ``` BOOT ```.

       • Jika pesan: ``` Done Uploading ``` telah muncul -> ``` Program yang diisikan tadi sudah bisa dioperasikan ```.

       • Jangan tekan tombol ``` BOOT ``` dan ``` EN ``` secara bersamaan karena hal ini bisa beralih ke mode ``` Unggah Firmware ```.

    </td></tr></table><br>

11. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan Arduino IDE untuk Kompilasi Binary
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
      
      • ``` LED_Blink_OTA.ino ```

      • ``` Monitoring_Controlling_Device_OTA.ino ```
         
   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```
         
   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` DOIT ESP32 DEVKIT V1 ```
            
      </th></tr>
      <tr><td width="810">
         
      • Cara: klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp32 ```.

      • Kemudian pilih papan dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">

      Unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```
         
   </td></tr></table><br>

5. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang anda gunakan saat ini.<br><br>

6. Selanjutnya, pilih ``` Sketch ``` -> ``` Export compiled Binary ```.<br><br>
    
7. Tunggu hingga proses selesai, file Biner (.bin) yang dihasilkan kemudian siap digunakan untuk proses OTA.

<br><br>

## Pengaturan Pembaruan Firmware Over-The-Air (FOTA)
1. Silakan login terlebih dahulu melalui ``` Local Web Server ```.

   <table><tr><td width="810">
      
      • Username: ``` admin ```

      • Password: ``` admin ```
         
   </td></tr></table><br>
   
2. Unggah file biner (.bin) secara bergantian untuk mengetahui perbedaan pada setiap versi pembaruan firmware.

   <table><tr><td width="810">

      • ``` LED_Blink_OTA.bin ```

      • ``` Monitoring_Controlling_Device_OTA.bin ```
         
   </td></tr></table>

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>
   
2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
    
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>

5. Selamat menikmati [Selesai].

<br><br>

## Sorotan

<table>
<tr>
<th width="840" colspan="4">Masuk Web Server</th>
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
<th width="840">Dasbor Web Server</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Dashboard.jpg" alt="dashboard"></td>
</tr>
</table>
<table>
<tr>
<th width="840" colspan="4">Kontrol LED</th>
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
<th width="420">Pemasangan Firmware Awal</th>
<th width="420">FOTA</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Initial Firmware Flashing.jpg" alt="initial-firmware-flashing"></td>
<td align="center"><img src="Assets/Documentation/Experiment/FOTA.jpg" alt="fota"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Unduh CSV</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Download CSV.jpg" alt="download-csv"></td>
</tr>
</table>

<br>
<strong>Informasi lebih lanjut:</strong> <a href="https://github.com/cakraawijaya/Local-WebBase-FOTA/blob/master/Assets/Documentation/Report/Portofolio%20Pelatihan%20Sertifikasi%20BNSP%20IIoT%20-%20Devan%20Cakra%20Mudra%20Wijaya-36-48.pdf"><u>Klik Disini</u></a>

<br><br>

## Apresiasi
Jika karya ini bermanfaat bagi anda, maka dukunglah karya ini sebagai bentuk apresiasi kepada penulis dengan mengklik tombol ``` ⭐Bintang ``` di bagian atas repositori.

<br><br>

## Penafian
Aplikasi ini merupakan hasil pengembangan dari Bootcamp Edutic.id x BNSP 2026. Saya tidak memungkiri bahwa saya masih menggunakan layanan pihak ketiga dalam pengerjaan ini, antara lain: library, framework, dan lain sebagainya.
