# Ultrasonic Parking Assistant

## Project Overview

The Ultrasonic Parking Assistant is an Arduino Uno-based project that helps measure the distance between a vehicle and an obstacle using an HC-SR04 ultrasonic sensor. The system provides visual and audible alerts through LEDs and a buzzer based on the measured distance. As the object gets closer, the beep frequency increases, simulating a real car parking sensor.

---

## Features

* Real-time distance measurement using the HC-SR04 Ultrasonic Sensor
* Four parking zones:

  * Safe
  * Caution
  * Close
  * Danger
* Green, Yellow, and Red LED indications
* Variable buzzer alert based on distance
* Live distance and zone information displayed on the Serial Monitor
* Noise reduction using multiple sensor readings

---

## Components Used

* Arduino Uno R3
* HC-SR04 Ultrasonic Sensor
* Active Buzzer
* Green LED
* Yellow LED
* Red LED
* 220Ω Resistors
* Breadboard
* Jumper Wires

---

## Wiring Summary

| Component       | Arduino Pin |
| --------------- | ----------- |
| Ultrasonic TRIG | D9          |
| Ultrasonic ECHO | D10         |
| Green LED       | D2          |
| Yellow LED      | D3          |
| Red LED         | D4          |
| Buzzer          | D6          |

---

## Working Principle

The HC-SR04 sensor sends an ultrasonic pulse and measures the time taken for the echo to return. The Arduino calculates the distance using the speed of sound.

Distance Formula:

**Distance (cm) = (Echo Time × 0.034) / 2**

The system continuously monitors the distance and changes the LED indication and buzzer frequency according to the following zones:

| Distance    | Zone    | Indication                  |
| ----------- | ------- | --------------------------- |
| Above 60 cm | Safe    | Green LED, No Buzzer        |
| 30–60 cm    | Caution | Yellow LED, Slow Beep       |
| 15–30 cm    | Close   | Yellow + Red LED, Fast Beep |
| Below 15 cm | Danger  | Red LED, Continuous Buzzer  |

---

## Expected Serial Monitor Output

```text
Distance : 82 cm | Zone : SAFE
Distance : 45 cm | Zone : CAUTION
Distance : 24 cm | Zone : CLOSE
Distance : 10 cm | Zone : DANGER
```

---

## How to Run

1. Connect all components according to the wiring table.
2. Upload the Arduino sketch to the Arduino Uno.
3. Open the Serial Monitor (115200 baud or as configured in the code).
4. Move your hand or an object towards the ultrasonic sensor.
5. Observe the LED indication, buzzer alert, and Serial Monitor output.

---

## Project Folder Structure

```text
p3-parking-sensor/
│── ultrasonic_parking_assistant.ino
│── README.md
│── serial_output.png
│── circuit_diagram.png
```

---

## Deliverables

* Arduino source code (`ultrasonic_parking_assistant.ino`)
* README.md
* Serial Monitor output screenshot
* Circuit diagram or wiring image
* Demo video (Google Drive link)

---

## Demo Video

Google Drive Link:

*Paste your Google Drive demo video link here.*

---

## Author

**Sangili Murugan**

BE Electronics and Communication Engineering

Arjun College of Technology

IIT Jammu Summer School 2026 – IoT & Drones Program
