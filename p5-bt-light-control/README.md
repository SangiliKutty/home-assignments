# Bluetooth Home Light Controller

## Project Overview

This project demonstrates a Bluetooth-based home light control system using the ESP32 Development Board. The ESP32 communicates with an Android phone via Classic Bluetooth (SPP), allowing users to control two relay channels that simulate home lighting. Physical push buttons provide manual control, while a buzzer confirms every valid command.

---

## Features

* Bluetooth control using ESP32 Classic Bluetooth
* Control two lights independently
* Turn all lights ON/OFF with a single command
* Manual push-button control
* Buzzer confirmation for every valid command
* Bluetooth status indication using the built-in LED
* Automatic light OFF after inactivity
* Real-time status response to the mobile application

---

## Components Used

* ESP32 Dev Board
* 2-Channel Relay Module
* 2 LEDs (Light Simulation)
* 220Ω Resistors
* Push Buttons
* Active Buzzer
* Breadboard
* Jumper Wires
* Android Phone with Serial Bluetooth Terminal App

---

## Wiring Summary

| Component    | ESP32 Pin |
| ------------ | --------- |
| Relay IN1    | GPIO26    |
| Relay IN2    | GPIO27    |
| Button 1     | GPIO0     |
| Button 2     | GPIO35    |
| Buzzer       | GPIO25    |
| Built-in LED | GPIO2     |

---

## Bluetooth Configuration

**Bluetooth Device Name**

```
IIT_IoT_HomeCtrl
```

---

## Supported Commands

| Command | Function               |
| ------- | ---------------------- |
| 1       | Light 1 ON             |
| 2       | Light 1 OFF            |
| 3       | Light 2 ON             |
| 4       | Light 2 OFF            |
| 5       | All Lights ON          |
| 6       | All Lights OFF         |
| ?       | Display Current Status |

---

## Expected Output

* ESP32 appears as **IIT_IoT_HomeCtrl** in Bluetooth devices.
* Mobile phone connects successfully.
* Sending commands controls the corresponding relay.
* Buzzer beeps after every valid command.
* ESP32 returns the current relay status.
* Manual buttons also control the lights.

Example:

```
> 1
L1:ON L2:OFF

> 3
L1:ON L2:ON

> ?
L1:ON L2:ON

> 6
L1:OFF L2:OFF
```

---

## How to Run

1. Upload the Arduino sketch to the ESP32.
2. Power the ESP32 using a USB cable.
3. Install the **Serial Bluetooth Terminal** app on an Android phone.
4. Pair the phone with **IIT_IoT_HomeCtrl**.
5. Connect through the app.
6. Send the supported commands to control the lights.

---

## Project Folder

```
p5-bt-light-control/
│── bluetooth_home_light_controller.ino
│── README.md
│── bluetooth_terminal_output.png
│── circuit_diagram.png
```

---

## Demo Video

Google Drive Link:

```
https://drive.google.com/file/d/1sKf7OyG2re6zREDIOaLvmjLuF51QTzxT/view?usp=drive_link
```

---

## Author

**Sangili Murugan**

BE Electronics and Communication Engineering

Arjun College of Technology

IIT Jammu Summer School 2026 – IoT & Drones Program
