# Wi-Fi Weather Dashboard

## Project Overview

The Wi-Fi Weather Dashboard is an IoT-based weather monitoring system built using the ESP32. It collects real-time environmental data such as temperature, humidity, atmospheric pressure, altitude, and light intensity. The ESP32 hosts a web server that displays these values on a responsive dashboard accessible from any device connected to the same Wi-Fi network.

## Components Used

- ESP32 Dev Board
- DHT11 Temperature & Humidity Sensor
- BMP280 Pressure & Altitude Sensor
- LDR (Light Dependent Resistor)
- OLED Display (SSD1306 I2C)
- Breadboard
- Jumper Wires

## Features

- Connects ESP32 to Wi-Fi
- Displays Temperature and Humidity
- Displays Atmospheric Pressure
- Displays Altitude
- Measures Ambient Light Intensity
- Hosts a Live Web Dashboard
- Auto-refreshes sensor values every 10 seconds
- Provides sensor data in JSON format
- Displays Wi-Fi SSID and IP Address on OLED
- Automatically reconnects to Wi-Fi if disconnected

## Wiring

- DHT11 DATA → GPIO4
- BMP280 SDA → GPIO21
- BMP280 SCL → GPIO22
- OLED SDA → GPIO21
- OLED SCL → GPIO22
- LDR Output → GPIO34

## Libraries

- WiFi
- ESPAsyncWebServer
- DHTesp
- Adafruit BMP280
- Adafruit SSD1306
- Adafruit GFX

## How to Run

1. Install all required libraries.
2. Update the Wi-Fi SSID and password in the code.
3. Upload the sketch to the ESP32.
4. Open the Serial Monitor to find the ESP32 IP address.
5. Enter the IP address into a web browser connected to the same Wi-Fi network.

## Expected Output

- OLED displays Wi-Fi connection status and IP address.
- Web dashboard displays all sensor readings.
- Dashboard updates automatically every 10 seconds.
- JSON data is available through the `/data` endpoint.

## Author

Sangili Murugan
