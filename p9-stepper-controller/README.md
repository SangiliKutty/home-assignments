# Stepper Motor Precision Positioner

## Project Overview

The Stepper Motor Precision Positioner is an Arduino-based motion control system that precisely rotates a 28BYJ-48 stepper motor using a ULN2003 driver board. A potentiometer is used to set the target position (0°–360°), while push buttons allow clockwise rotation, counter-clockwise rotation, and setting the current position as the Home position. An OLED display shows the current angle, target angle, motor direction, and total steps moved.

## Components Used

- Arduino Uno R3
- 28BYJ-48 Stepper Motor
- ULN2003 Driver Board
- 10kΩ Potentiometer
- OLED Display (SSD1306 I2C)
- 3 Push Buttons
- LED with 220Ω Resistor
- Breadboard
- Jumper Wires

## Features

- Precise stepper motor position control
- Potentiometer-controlled target angle
- Clockwise and Counter-Clockwise manual rotation
- Home position reset
- OLED displays current position and direction
- Tracks total motor steps
- Serial Monitor logs motor movements

## Wiring

- ULN2003 IN1 → Pin 8
- ULN2003 IN2 → Pin 9
- ULN2003 IN3 → Pin 10
- ULN2003 IN4 → Pin 11
- Potentiometer Output → A0
- CW Button → Pin 2
- CCW Button → Pin 3
- Home Button → Pin 4
- OLED SDA → A4
- OLED SCL → A5
- LED → Pin 13

## Libraries

- Stepper
- Adafruit SSD1306
- Adafruit GFX

## How to Run

1. Install all required libraries.
2. Connect all hardware according to the wiring diagram.
3. Upload the sketch to the Arduino Uno.
4. Rotate the potentiometer to set the target angle.
5. Use the buttons to move the motor and set the Home position.
6. Observe the motor movement and OLED display.

## Expected Output

- OLED displays:
  - Current Angle
  - Target Angle
  - Motor Direction
  - Total Steps
- Stepper motor rotates accurately to the selected position.
- Serial Monitor displays movement information.

## Author

Sangili Murugan
