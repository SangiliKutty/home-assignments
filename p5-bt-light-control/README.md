# Bluetooth Home Light Controller

## Project Overview

The Bluetooth Home Light Controller is an IoT-based home automation project that allows users to control two lights using an Android smartphone via Bluetooth. The ESP32 receives Bluetooth commands to switch relays on or off, while manual push buttons provide local control. The system also sends confirmation messages back to the mobile device and provides audible feedback using a buzzer.

## Components Used

- ESP32 Dev Board
- 2-Channel Relay Module
- LEDs (to simulate lights)
- Push Buttons
- Active Buzzer
- Breadboard
- Jumper Wires

## Features

- Bluetooth communication using ESP32 Classic Bluetooth
- Mobile phone control of two lights
- Manual push-button override
- Confirmation beep for every command
- Bluetooth status indication using the onboard LED
- Automatic timeout to turn off lights after inactivity
- Real-time status messages sent to the Bluetooth terminal

## Wiring

- Relay IN1 → GPIO26
- Relay IN2 → GPIO27
- Push Button 1 → GPIO0
- Push Button 2 → GPIO35
- Buzzer → GPIO25
- Built-in LED (GPIO2) → Bluetooth connection indicator

## Libraries

- BluetoothSerial

## Commands

- 1 → Light 1 ON
- 2 → Light 1 OFF
- 3 → Light 2 ON
- 4 → Light 2 OFF
- 5 → All Lights ON
- 6 → All Lights OFF
- ? → Display Current Status

## Author

Sangili Murugan
