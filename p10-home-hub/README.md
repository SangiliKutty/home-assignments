# Full IoT Home Automation Hub

## Project Overview

The Full IoT Home Automation Hub is an ESP32-based smart home system that integrates multiple sensors, automation, OLED display, Wi-Fi, and MQTT communication into a single platform. The system continuously monitors room temperature, humidity, gas leakage, motion, and ambient light, while automatically controlling a fan and room light through relays. It also hosts a web dashboard and publishes sensor data to an MQTT broker for real-time remote monitoring.

---

## Features

* Real-time monitoring of temperature and humidity using DHT11
* Gas leakage detection using MQ-2 sensor
* Motion detection using PIR sensor
* Ambient light detection using LDR
* Automatic fan control based on temperature
* Automatic light control based on light level and motion
* Gas safety shutdown with buzzer and LED alert
* OLED display with multiple information screens
* Web dashboard using ESP32 AsyncWebServer
* MQTT data publishing to HiveMQ broker
* Manual relay override using push buttons
* System uptime monitoring using `millis()`

---

## Components Used

* ESP32 Dev Board
* DHT11 Temperature & Humidity Sensor
* MQ-2 Gas Sensor
* PIR Motion Sensor (HC-SR501)
* LDR with 10kΩ Resistor
* 2-Channel Relay Module
* OLED Display (SSD1306 I2C)
* Active Buzzer
* Red LED
* Green LED
* Two Push Buttons
* Breadboard
* Jumper Wires

---

## Wiring Summary

| Component             | ESP32 Pin |
| --------------------- | --------- |
| DHT11 Data            | GPIO4     |
| MQ-2 Analog Output    | GPIO35    |
| PIR Output            | GPIO13    |
| LDR                   | GPIO34    |
| Relay 1 (Fan)         | GPIO26    |
| Relay 2 (Light)       | GPIO27    |
| Buzzer                | GPIO14    |
| Red LED               | GPIO25    |
| Green LED             | GPIO2     |
| Fan Override Button   | GPIO0     |
| Light Override Button | GPIO32    |
| OLED SDA              | GPIO21    |
| OLED SCL              | GPIO22    |

---

## Working Principle

The ESP32 reads all sensor values every 5 seconds.

### Fan Automation

* Turns ON automatically when the temperature exceeds **32°C**.
* Turns OFF automatically when the temperature drops below **28°C**.

### Light Automation

* Turns ON when the room is dark and motion is detected.
* Turns OFF when daylight is detected or no motion is present for 3 minutes.

### Gas Safety

* If gas concentration exceeds the safety threshold:

  * Buzzer turns ON
  * Red LED glows
  * Both relays turn OFF
  * Alert message is published to the MQTT broker

### OLED Display

The OLED automatically switches between three screens:

* Temperature & Humidity
* Gas, PIR and Light Status
* Relay Status & System Uptime

### Web Dashboard

The ESP32 hosts a web dashboard displaying:

* Temperature
* Humidity
* Gas Level
* Motion Status
* Light Level
* Relay Status
* Manual Control Buttons
* System Uptime

### MQTT Communication

Sensor readings are published every 30 seconds in JSON format.

Example Topic:

```text id="mg8rpb"
iitjammu/sangilimurugan/home
```

Example JSON:

```text id="iwdww2"
{
  "temp": 29,
  "humidity": 64,
  "gas": 18,
  "pir": 1,
  "light": 45,
  "fan": "OFF",
  "light_relay": "ON",
  "alert": "SAFE"
}
```

---

## Expected Output

### OLED

```text id="1mv22l"
Temp : 29°C
Humidity : 64%
```

```text id="vw6x5d"
Gas : SAFE
Motion : YES
Light : 42%
```

```text id="w8duz4"
Fan : OFF
Light : ON
Uptime : 00:15:42
```

### Serial Monitor

```text id="sk1q6v"
Temperature : 29°C
Humidity : 64%
Gas Level : SAFE
Motion : Detected
Light Level : 42%
Fan : OFF
Light : ON
MQTT Published Successfully
```

---

## How to Run

1. Assemble the circuit according to the wiring table.
2. Install all required Arduino libraries.
3. Update the Wi-Fi SSID and password in the source code.
4. Upload the program to the ESP32.
5. Open the Serial Monitor (115200 baud).
6. Connect the ESP32 to Wi-Fi.
7. Access the web dashboard using the ESP32 IP address.
8. Monitor MQTT messages using MQTT Explorer.

---

## Project Folder Structure

```text id="z1jzyv"
p10-home-hub/
│── iot_home_automation_hub.ino
│── README.md
│── web_dashboard.png
│── mqtt_output.png
│── serial_output.png
│── circuit_diagram.png
```

---

## Deliverables

* ESP32 source code (`iot_home_automation_hub.ino`)
* README.md
* Web dashboard screenshot
* MQTT Explorer screenshot
* Serial Monitor screenshot
* Circuit diagram
* Demo video (Google Drive link)

---

## Demo Video

Google Drive Link:

https://drive.google.com/file/d/1xN92O8q0gnLaAvXiEuIQ_58yVyPO12kw/view?usp=drive_link

---

## GitHub Repository

https://github.com/SangiliKutty/home-assignments/edit/main/p10-home-hub/README.md

---

## Author

**Sangili Murugan**

BE Electronics and Communication Engineering

Arjun College of Technology

**IIT Jammu Summer School 2026 – IoT & Drones Program**
