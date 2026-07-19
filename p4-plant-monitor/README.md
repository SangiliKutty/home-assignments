# Smart Plant Watering Monitor

## Project Overview

The Smart Plant Watering Monitor is an IoT-based system that monitors soil moisture, temperature, and humidity using an ESP32. It automatically activates a relay (simulating a water pump) when the soil becomes dry and displays real-time sensor data on an OLED display.

## Components Used

- ESP32 Dev Board
- Capacitive Soil Moisture Sensor
- DHT11 Temperature & Humidity Sensor
- OLED Display (SSD1306 I2C)
- 2-Channel Relay Module
- Push Button
- Active Buzzer
- Red LED
- Green LED
- Breadboard
- Jumper Wires

## Features

- Measures soil moisture percentage
- Displays moisture, temperature, and humidity on OLED
- Automatic watering using relay control
- Manual watering override button
- Hysteresis logic to prevent rapid relay switching
- Serial Monitor data logging

## Wiring

- Soil Moisture Sensor AOUT → GPIO34
- DHT11 DATA → GPIO4
- OLED SDA → GPIO21
- OLED SCL → GPIO22
- Relay IN1 → GPIO26
- Relay IN2 → GPIO27
- Push Button → GPIO0
- Buzzer → GPIO25

## Libraries

- DHTesp
- Adafruit SSD1306
- Adafruit GFX

## Author

Sangili Murugan
