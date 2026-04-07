# AURORA-X Tactical 4WD Surveillance Rover
*A Long-Range RF-Controlled Vehicle with Live Camera Feed*

## Overview
The AURORA-X Tactical 4WD Surveillance Rover is an advanced, long-range robotic vehicle designed for security, robotics, and IoT deployments. It uses a dual Arduino Nano setup, NRF24L01+ PA + LNA transceivers for long-range wireless communication, an ESP32-CAM for real-time video surveillance, and an L298N dual H-bridge driver to power a 4-wheel-drive system.

## System Architecture
The system is divided into two major segments:

### 1. Remote Control Transmitter Unit
A user-operated handheld controller with dual joysticks.

![Trransmitter](<Screenshot 2026-04-07 061505.png>)
![Receiver ](<Screenshot 2026-04-07 061505-1.png>)
### 2. Vehicle Receiver Unit
The 4WD rover equipped with video surveillance and a servo-controlled camera mount.

*(Note: Upload the picture of your vehicle from Page 4 of your report to GitHub and ensure it is named `vehicle_receiver.jpg`)*
![Vehicle Receiver Unit](vehicle_receiver.jpg)

## Hardware Components
* **Microcontrollers:** 2x Arduino Nano (ATmega328P)
* **Communication:** 2x NRF24L01+ PA + LNA (2.4 GHz)
* **Motor Control:** 1x L298N Motor Driver, 4x DC Gear Motors (4WD)
* **Inputs (Remote):** 2x Analog Joystick Modules
* **Vision & Actuation:** 1x ESP32-CAM, 1x Servo Motor
* **Power Supply:** 7.4V Li-ion/LiPo battery pack (Vehicle), 5V USB/9V battery (Remote)

## Pin Configurations & Wiring

### 1. Remote Unit (Transmitter)
**Joysticks to Arduino Nano:**
* **Joystick 1 (Movement):** VRx -> A0, VRy -> A1, VCC -> 5V, GND -> GND
* **Joystick 2 (Servo):** VRx -> A2, VRy -> A3, VCC -> 5V, GND -> GND

**NRF24L01+ to Arduino Nano:**
| NRF24 Pin | Arduino Nano Pin |
| :--- | :--- |
| VCC | 3.3V |
| GND | GND |
| CE | D9 |
| CSN | D10 |
| MOSI | D11 |
| MISO | D12 |
| SCK | D13 |


### 2. Vehicle Unit (Receiver)
**NRF24L01+ to Arduino Nano:**
| NRF24 Pin | Arduino Nano Pin |
| :--- | :--- |
| VCC | 3.3V |
| GND | GND |
| CE | D7 |
| CSN | D8 |
| MOSI | D11 |
| MISO | D12 |
| SCK | D13 |


**L298N Motor Driver to Arduino Nano:**
| L298N Pin | Arduino Nano Pin |
| :--- | :--- |
| IN1 | D3 |
| IN2 | D4 |
| IN3 | D5 |
| IN4 | D6 |
| ENA / ENB | Jumper On |


*Note: The servo motor signal wire connects to D9, powered by 5V. The ESP32-CAM utilizes an external 5V buck converter with a common ground to the Arduino.*

## Tactical & Security Applications
* **Remote Reconnaissance:** Enables safe scouting in hazardous or restricted zones.
* **Visual Surveillance:** Real-time crowd monitoring, perimeter defense, and disaster response.
* **Secure Communication:** Utilizes address-defined packet transmission and noise-resistant communication.

## Future Enhancements
* **Autonomous Navigation & AI:** SLAM-based mapping and computer vision obstacle detection.
* **GPS Integration:** GPS-based mission logging and geofencing.
* **Encrypted RF:** AES encryption and frequency-hopping spread spectrum.
* **Payload Upgrades:** Multi-sensor data fusion (LiDAR, thermal imaging, environmental detectors).

---
**Author:** Vishvjeet Dangi  
**Institution:** Rashtriya Raksha University, School of Applied Sciences, Engineering and Technology (SASET)
