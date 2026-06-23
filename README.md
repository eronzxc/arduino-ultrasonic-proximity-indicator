# 3-Stage Proximity Level Indicator with Arduino Uno

A modular embedded systems hardware prototype that utilizes an **HC-SR04 Ultrasonic Distance Sensor** to measure object proximity in real-time. The system processes the pulse timing inputs and triggers a 3-stage visual alert system using color-coded LEDs (Green, Yellow, Red) based on defined distance threshold matrices.

## 🚀 Features
* **Real-time Pulse Timing Calculation:** Converts echo durations into precise centimeter metrics from scratch.
* **3-Tier Proximity Alert System:**
  * 🟢 **Safe Zone (20cm - 35cm):** Green LED active.
  * 🟡 **Warning Zone (10cm - 19cm):** Yellow LED active.
  * 🔴 **Danger Zone (<10cm):** Red LED active with Serial Console breach warning flags.
* **Modular Code Architecture:** Designed with specialized functional logic blocks for seamless troubleshooting and sensory isolation.

## 🔌 Hardware Architecture & Wiring

| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **HC-SR04 VCC** | 5V | Main Power Rail |
| **HC-SR04 GND** | GND | Common Ground |
| **HC-SR04 Trig** | Digital Pin 9 | Ultrasonic Trigger Input |
| **HC-SR04 Echo** | Digital Pin 10 | Echo Duration Output |
| **Green LED** | Digital Pin 5 | Safe Status Indicator |
| **Yellow LED** | Digital Pin 6 | Warning Status Indicator |
| **Red LED** | Digital Pin 7 | Critical Alert Indicator |

## 🛠️ Software Stack
* **Language:** Embedded C++ (Arduino Wiring)
* **IDE:** Arduino IDE v2.x
* **Communication Protocol:** UART Serial Communication @ 9600 Baud Rate

## 📖 System Logic Overview
The core loop triggers a high-frequency 10-microsecond sonic burst via the `trgPin`. The execution halts sequentially using `pulseIn()` to calculate the round-trip microsecond return window. This is mathematically converted to centimeters using the constant speed of sound boundary equation:
$$\text{Distance (cm)} = \frac{\text{Duration}}{29.1} \div 2$$
The localized threshold matrix evaluates the returned integer and switches the matching digital GPIO pins high or low dynamically with an execution polling cycle of 150ms.
