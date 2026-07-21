# Gas & Fire Safety Alert System

## Project Overview

The Gas & Fire Safety Alert System is an Arduino Uno-based safety project designed to detect gas leaks and fire hazards in real time. It uses an MQ-2 Gas Sensor and a Flame Sensor to continuously monitor the environment and provide immediate visual and audible alerts through LEDs and a buzzer. The system helps improve home and kitchen safety by providing three alert levels: Safe, Warning, and Danger.

---

## Features

* Real-time gas leak detection using the MQ-2 sensor
* Fire detection using the Flame Sensor
* Three safety levels:

  * Safe (Green LED)
  * Warning (Yellow LED + Slow Buzzer)
  * Danger (Red LED + Continuous Buzzer)
* Independent gas and flame detection logic
* Live status displayed on the Serial Monitor
* Easy to build using Arduino Uno

---

## Components Used

* Arduino Uno R3
* MQ-2 Gas Sensor
* Flame Sensor
* Active Buzzer
* Green LED
* Yellow LED
* Red LED
* 220Ω Resistors
* Breadboard
* Jumper Wires

---

## Wiring Summary

| Component                   | Arduino Pin   |
| --------------------------- | ------------- |
| MQ-2 Analog Output          | A0            |
| Flame Sensor Digital Output | D7            |
| Flame Sensor Analog Output  | A1 (Optional) |
| Green LED                   | D10           |
| Yellow LED                  | D11           |
| Red LED                     | D12           |
| Buzzer                      | D9            |

---

## Working Principle

The MQ-2 sensor continuously measures gas concentration, while the flame sensor detects the presence of fire.

* **Safe:** Gas level below 30% and no flame detected.
* **Warning:** Gas level between 30% and 60%.
* **Danger:** Gas level above 60% or flame detected.

The LEDs and buzzer indicate the current safety level, and the Serial Monitor displays the system status every second.

---

## Expected Serial Monitor Output

```text
GAS: 18% | FLAME: NONE | STATUS: SAFE
GAS: 42% | FLAME: NONE | STATUS: WARNING
GAS: 72% | FLAME: NONE | STATUS: DANGER
GAS: 35% | FLAME: DETECTED | STATUS: DANGER
```

---

## How to Run

1. Connect all components according to the wiring table.
2. Upload the Arduino sketch to the Arduino Uno.
3. Open the Serial Monitor (115200 baud or as configured in the code).
4. Allow the MQ-2 sensor to warm up for about 2 minutes.
5. Test the gas sensor and flame sensor.
6. Observe LED indications, buzzer alerts, and Serial Monitor output.

---

## Project Folder Structure

```text
p2-gas-fire-alert/
│── gas_fire_safety_alert.ino
│── README.md
│── serial_output.png
│── circuit_diagram.png
```

---

## Deliverables

* Arduino source code (`gas_fire_safety_alert.ino`)
* README.md
* Serial Monitor screenshot
* Circuit diagram or wiring image
* Demo video (Google Drive link)

---

## Demo Video

Google Drive Link:

https://drive.google.com/file/d/1M-EwNqL-rldT_jbUzUOKuDFA-hym1F_6/view?usp=drive_link

---

## Author

**Sangili Murugan**

BE Electronics and Communication Engineering

Arjun College of Technology

IIT Jammu Summer School 2026 – IoT & Drones Program
