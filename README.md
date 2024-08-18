# smart-dustbin-using-IOT
This project demonstrates how to build a Smart Dustbin using IoT components, such as an ultrasonic sensor, Arduino, and a servo motor, combined with IFTTT Webhooks for notifications.

## Project Overview

The Smart Dustbin automatically opens its lid when it detects someone approaching, using an ultrasonic sensor. Additionally, it can send a notification when the dustbin is full using IFTTT Webhooks.

## Repository Structure

- `code/`: Contains the Arduino code for triggering the IFTTT webhook.
- `images/`: Photos and images related to the project.
- `README.md`: This file, providing an overview and instructions.
- `requirements.txt`:This file provides the required material to build the project

## Getting Started

### Prerequisites

#### Hardware Components:
- Arduino Uno
- IR sensor
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Wi-Fi Module (ESP8266 or ESP32)
- Breadboard and Jumper Wires

#### Software:
- Arduino IDE

### Hardware Setup

1. **Circuit Diagram:**
   - Refer to the circuit diagram in the `hardware/` directory (`circuit_diagram.png`).
   - Connect the ultrasonic sensor and servo motor to the Arduino as shown.

2. **Component List:**
   - A detailed list of components and their specifications can be found in `hardware/parts_list.md`.

### Demo

You can see the Smart Dustbin in action in the `images/` directory (`smart_dustbin.jpg`).


