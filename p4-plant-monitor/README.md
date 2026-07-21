# Smart Plant Watering Monitor

## Project Overview

The Smart Plant Watering Monitor is an ESP32-based IoT project that monitors soil moisture, temperature, and humidity to help maintain healthy plant growth. The system automatically activates a relay (simulating a water pump) when the soil becomes dry and displays real-time sensor data on an OLED display. A manual override button allows the user to water the plant whenever needed.

---

## Features

* Real-time soil moisture monitoring
* Temperature and humidity measurement using DHT11
* Automatic relay control for watering
* Manual watering override using a push button
* OLED display showing live sensor readings
* Green and Red LED status indication
* Buzzer alert during watering operation
* Serial Monitor logging for monitoring sensor values

---

## Components Used

* ESP32 Dev Board
* Capacitive Soil Moisture Sensor
* DHT11 Temperature & Humidity Sensor
* 2-Channel Relay Module
* OLED Display (SSD1306)
* Push Button
* Active Buzzer
* Green LED
* Red LED
* Breadboard
* Jumper Wires

---

## Wiring Summary

| Component            | ESP32 Pin |
| -------------------- | --------- |
| Soil Moisture Sensor | GPIO34    |
| DHT11 Data           | GPIO4     |
| OLED SDA             | GPIO21    |
| OLED SCL             | GPIO22    |
| Relay IN1            | GPIO26    |
| Relay IN2            | GPIO27    |
| Push Button          | GPIO0     |
| Green LED            | GPIO25    |
| Red LED              | GPIO33    |
| Buzzer               | GPIO32    |

---

## Working Principle

The ESP32 continuously reads soil moisture, temperature, and humidity values.

* **Dry Soil (<30%)** – Relay turns ON to simulate the water pump.
* **Optimal Soil (30–70%)** – Relay remains OFF.
* **Wet Soil (>70%)** – Relay stays OFF.

The OLED displays the current moisture percentage, temperature, humidity, and system status. The push button activates manual watering for a short duration before returning to automatic mode.

---

## Expected Output

### OLED Display

```text
Soil : 45 %
Temp : 28 °C
Humidity : 65 %
Status : OPTIMAL
```

### Serial Monitor

```text
Moisture : 24% | Temp : 29°C | Humidity : 66% | Pump : ON
Moisture : 38% | Temp : 28°C | Humidity : 64% | Pump : OFF
Moisture : 72% | Temp : 27°C | Humidity : 63% | Pump : OFF
```

---

## How to Run

1. Connect all components according to the wiring table.
2. Upload the Arduino sketch to the ESP32.
3. Open the Serial Monitor.
4. Place the soil moisture sensor in dry and wet soil to observe changes.
5. Verify relay operation, OLED updates, LEDs, and buzzer response.
6. Press the push button to test manual watering mode.

---

## Project Folder Structure

```text
p4-plant-monitor/
│── smart_plant_watering_monitor.ino
│── README.md
│── serial_output.png
│── circuit_diagram.png
```

---

## Deliverables

* Arduino source code (`smart_plant_watering_monitor.ino`)
* README.md
* Serial Monitor output screenshot
* Circuit diagram or wiring image
* Demo video (Google Drive link)

---

## Demo Video

Google Drive Link:

*Paste your Google Drive video link here.*

---

## Author

**Sangili Murugan**

BE Electronics and Communication Engineering

Arjun College of Technology

IIT Jammu Summer School 2026 – IoT & Drones Program
