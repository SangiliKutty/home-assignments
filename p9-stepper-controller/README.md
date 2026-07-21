# Stepper Motor Precision Positioner

## Project Overview

The Stepper Motor Precision Positioner is an Arduino Uno-based project that accurately controls the position of a 28BYJ-48 stepper motor using a ULN2003 driver module. A potentiometer is used to set the target angle, while push buttons allow clockwise (CW), counter-clockwise (CCW), and Home position control. The OLED display shows the current angle, target angle, motor direction, and total steps moved.

---

## Features

* Precise stepper motor position control
* Potentiometer-based target angle selection (0°–360°)
* Clockwise and Counter-Clockwise manual control
* Home position reset button
* OLED display for motor status
* Serial Monitor position tracking
* Accurate angle calculation using motor steps

---

## Components Used

* Arduino Uno R3
* 28BYJ-48 Stepper Motor
* ULN2003 Stepper Driver Module
* 10kΩ Potentiometer
* 3 Push Buttons
* OLED Display (SSD1306)
* LED
* 220Ω Resistor
* Breadboard
* Jumper Wires

---

## Wiring Summary

| Component     | Arduino Pin |
| ------------- | ----------- |
| ULN2003 IN1   | D8          |
| ULN2003 IN2   | D9          |
| ULN2003 IN3   | D10         |
| ULN2003 IN4   | D11         |
| Potentiometer | A0          |
| CW Button     | D2          |
| CCW Button    | D3          |
| Home Button   | D4          |
| OLED SDA      | A4          |
| OLED SCL      | A5          |
| Status LED    | D13         |

---

## Working Principle

The potentiometer sets the desired target angle between **0° and 360°**. The Arduino calculates the required number of motor steps and rotates the stepper motor accordingly.

* **CW Button** – Rotates the motor 45° clockwise.
* **CCW Button** – Rotates the motor 45° counter-clockwise.
* **Home Button** – Sets the current position as 0° without moving the motor.

The OLED continuously displays:

* Current Angle
* Target Angle
* Direction (CW/CCW)
* Total Steps

The Serial Monitor logs every motor movement and position update.

---

## Expected OLED Output

```text
Current : 135°
Target  : 270°
Dir     : CW
Steps   : 1536
```

---

## Expected Serial Monitor Output

```text
Stepper Position Controller

Target Angle : 180°
Current Angle : 135°
Direction : CW
Steps Moved : 256

Target Angle : 270°
Current Angle : 270°
Direction : CW
Steps Moved : 512

Home Position Set
Current Angle : 0°
```

---

## How to Run

1. Connect all components according to the wiring table.
2. Upload the Arduino sketch to the Arduino Uno.
3. Open the Serial Monitor.
4. Rotate the potentiometer to change the target angle.
5. Press the CW or CCW button to rotate the motor.
6. Press the Home button to reset the current position.
7. Observe the OLED display and Serial Monitor updates.

---

## Project Folder Structure

```text
p9-stepper-controller/
│── stepper_motor_positioner.ino
│── README.md
│── serial_output.png
│── circuit_diagram.png
```

---

## Deliverables

* Stepper motor control source code (`stepper_motor_positioner.ino`)
* README.md
* Serial Monitor output screenshot
* Circuit diagram or hardware setup image
* OLED display photo
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
