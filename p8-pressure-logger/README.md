# IoT Pressure & Altitude Logger

## Project Overview

The IoT Pressure & Altitude Logger is an ESP32-based environmental monitoring system that measures atmospheric pressure, temperature, and altitude using a BMP280 sensor. The system stores pressure readings, analyzes pressure trends, displays data on an OLED screen, and helps predict weather changes based on pressure variations.

## Components Used

- ESP32 Dev Board
- BMP280 Pressure & Altitude Sensor
- OLED Display (SSD1306 I2C)
- 10kΩ Potentiometer
- Green LED
- Red LED
- Breadboard
- Jumper Wires

## Features

- Measures atmospheric pressure
- Displays altitude and temperature
- Stores the last 24 pressure readings
- Detects Rising, Falling, or Stable pressure trends
- Displays trend indicators on OLED
- Uses a potentiometer to adjust altitude reference
- Prints sensor readings to the Serial Monitor
- Supports MQTT publishing (Bonus Challenge)

## Wiring

- BMP280 SDA → GPIO21
- BMP280 SCL → GPIO22
- OLED SDA → GPIO21
- OLED SCL → GPIO22
- Potentiometer Output → GPIO34
- Green LED → GPIO25
- Red LED → GPIO26

## Libraries

- Adafruit BMP280
- Adafruit SSD1306
- Adafruit GFX

## How to Run

1. Install all required libraries.
2. Connect the hardware according to the wiring table.
3. Upload the code to the ESP32.
4. Open the Serial Monitor at 115200 baud.
5. Observe pressure, altitude, and temperature values on the OLED and Serial Monitor.

## Expected Output

- OLED displays pressure, altitude, and temperature.
- Trend arrow indicates Rising, Falling, or Stable pressure.
- Pressure readings are logged continuously.
- LEDs indicate weather trend status.

## Author

Sangili Murugan
