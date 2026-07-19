# Ultrasonic Parking Assistant

## Project Overview

This project uses an HC-SR04 Ultrasonic Sensor to measure the distance between the vehicle and nearby obstacles. It provides visual and audible alerts using LEDs and a buzzer, while displaying the measured distance on an OLED screen.

## Components Used

- Arduino Uno R3
- HC-SR04 Ultrasonic Sensor
- OLED Display (SSD1306 I2C)
- Active Buzzer
- Red LED
- Yellow LED
- Green LED
- 220Ω Resistors
- Breadboard
- Jumper Wires

## Features

- Measures distance accurately using an ultrasonic sensor
- Displays distance on OLED
- Four parking safety zones
- LED indication for each zone
- Buzzer frequency changes with obstacle distance
- Serial Monitor displays distance readings

## Wiring

- HC-SR04 TRIG → Pin 9
- HC-SR04 ECHO → Pin 10
- OLED SDA → A4
- OLED SCL → A5
- Green LED → Pin 2
- Yellow LED → Pin 3
- Red LED → Pin 4
- Buzzer → Pin 6

## Author

Sangili Murugan
