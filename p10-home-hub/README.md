# Full IoT Home Automation Hub

## Project Overview

The Full IoT Home Automation Hub is a comprehensive ESP32-based smart home system that integrates multiple sensors, relay modules, Wi-Fi connectivity, MQTT communication, and a web dashboard. The system monitors temperature, humidity, gas levels, motion, and ambient light while automatically controlling a fan and lighting based on predefined automation rules. It also provides real-time monitoring through an OLED display, web interface, and MQTT messages.

## Components Used

- ESP32 Dev Board
- DHT11 Temperature & Humidity Sensor
- MQ-2 Gas Sensor
- PIR Motion Sensor (HC-SR501)
- LDR (Light Dependent Resistor)
- 2-Channel Relay Module
- OLED Display (SSD1306 I2C)
- Active Buzzer
- Red LED
- Green LED
- Two Push Buttons
- Breadboard
- Jumper Wires

## Features

- Monitors temperature and humidity
- Detects gas leakage
- Detects motion using PIR sensor
- Measures ambient light intensity
- Automatic fan control using temperature
- Automatic light control using PIR and LDR
- Gas leak emergency shutdown
- OLED status display
- Web dashboard with live sensor values
- MQTT data publishing
- Manual relay override buttons
- System uptime display

## Wiring

- DHT11 DATA → GPIO4
- MQ-2 AOUT → GPIO35
- PIR OUT → GPIO13
- LDR Output → GPIO34
- Relay 1 (Fan) → GPIO26
- Relay 2 (Light) → GPIO27
- OLED SDA → GPIO21
- OLED SCL → GPIO22
- Buzzer → GPIO14
- Red LED → GPIO25
- Green LED → GPIO2
- Fan Override Button → GPIO0
- Light Override Button → GPIO32

## Libraries

- WiFi
- ESPAsyncWebServer
- PubSubClient
- DHTesp
- Adafruit SSD1306
- Adafruit GFX

## How to Run

1. Install all required libraries.
2. Update the Wi-Fi SSID and password.
3. Configure the MQTT broker settings.
4. Connect all hardware according to the wiring diagram.
5. Upload the code to the ESP32.
6. Open the Serial Monitor to obtain the ESP32 IP address.
7. Open the IP address in a web browser to access the dashboard.

## Expected Output

- OLED cycles through sensor information every 5 seconds.
- Web dashboard displays all sensor readings and relay status.
- Fan turns ON automatically when temperature exceeds the threshold.
- Light turns ON automatically when motion is detected in low light.
- Gas detection activates buzzer, LED, and emergency shutdown.
- MQTT publishes JSON sensor data every 30 seconds.

## Folder Contents

- home_hub.ino
- README.md
- circuit_diagram.jpg
- web_dashboard.png
- oled_display.png
- serial_monitor.png
- mqtt_output.png
- working_model.jpg
- demo_video_link.txt

## Author

Sangili Murugan
