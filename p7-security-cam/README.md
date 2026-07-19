# Motion-Activated Security Camera

## Project Overview

The Motion-Activated Security Camera is an IoT-based surveillance system built using the ESP32-CAM and a PIR motion sensor. The system detects motion, activates a live camera stream, sounds a buzzer, lights a warning LED, and logs motion events. This project helps monitor indoor environments while conserving power by remaining in standby mode until motion is detected.

## Components Used

- ESP32-CAM Module
- PIR Motion Sensor (HC-SR501)
- Active Buzzer
- Red LED
- USB-to-TTL (FTDI) Programmer
- Breadboard
- Jumper Wires

## Features

- Motion detection using PIR sensor
- Automatic camera activation
- Live video streaming through a web browser
- Motion event logging
- LED and buzzer alerts
- Automatic return to standby after no motion
- Serial Monitor status updates

## Wiring

- PIR OUT → GPIO13
- Red LED → GPIO2
- Buzzer → GPIO14
- FTDI TX → ESP32-CAM RX
- FTDI RX → ESP32-CAM TX
- FTDI 5V → ESP32-CAM 5V
- FTDI GND → ESP32-CAM GND
- GPIO0 → GND (only while uploading)

## Libraries

- WiFi
- esp_camera
- ESP32 CameraWebServer

## How to Run

1. Connect the ESP32-CAM using an FTDI programmer.
2. Connect GPIO0 to GND before uploading.
3. Upload the program.
4. Disconnect GPIO0 from GND and restart the board.
5. Connect to Wi-Fi and open the IP address shown in the Serial Monitor.
6. Walk in front of the PIR sensor to trigger motion detection.

## Expected Output

- Motion detection activates the camera stream.
- Red LED and buzzer turn ON.
- Live video appears in the browser.
- Motion events are displayed on the web page.
- System returns to standby after 60 seconds of no motion.

## Author

Sangili Murugan
