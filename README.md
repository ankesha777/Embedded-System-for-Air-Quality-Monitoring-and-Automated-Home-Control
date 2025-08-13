# Embedded-System-for-Air-Quality-Monitoring-and-Automated-Home-Control
an embedded system designed for air quality monitoring and automated home control uses an MQ-2 gas sensor to detect harmful gases and an LDR to measure ambient light levels. When gas concentration exceeds a safe threshold, the system activates a ventilation fan and flashes alert LEDs.

# Abstract
An embedded system that monitors indoor air quality and ambient light, then actuates a ventilation fan and lighting automatically. A gas sensor triggers visual alerts and fan control; an LDR enables light automation. The system demonstrates sensor interfacing, PWM motor control, digital I/O, and real-time decision logic on a microcontroller.

# Objectives
- Detect hazardous gas concentration and alert the user.
- Activate a fan when gas level rises above a threshold.
- Control lighting based on ambient brightness.
- Log sensor data over serial for testing and calibration.

# Hardware Components
1. Microcontroller: Arduino Uno/Nano
2. Gas Sensor: MQ-2 (or equivalent analog gas sensor)
3. LDR + 10 kΩ resistor (voltage divider)
4. Motor Driver: L293D or L298N
5. DC fan (5–12 V as per driver/supply)
6. LEDs (alert & lighting) + 220 Ω resistors
7. Breadboard/PCB, jumper wires, regulated power supply

# System Design Overview
- Sensors: MQ-2 on A1, LDR divider on A0.
- Actuators: Fan via motor driver (Enable on PWM pin 5; direction pins on 2 & 3). LEDs on D12 (alert) and D13 (light).
- Logic: If gasValue>150 → flash alert LEDs; if gasValue>100 → run fan; if ambient light low (ldrValue<1000) → turn on light.
- Telemetry: Serial prints of gas and LDR readings for debugging and threshold tuning.

# Circuit Connections 
- MQ-2 AO → A1; VCC → 5 V; GND → GND
- LDR divider → A0 (LDR to 5 V, fixed 10 kΩ to GND; junction → A0)
- Motor driver: EN → D5 (PWM), IN1 → D2, IN2 → D3; fan on driver outputs; driver Vmotor per fan rating; logic VCC 5 V
- LEDs: D12 (alert), D13 (light) each via 220 Ω to GND

# Software Flow (high level)
- Initialize I/O and Serial.
- Read gas sensor → print → compare with thresholds → alert & fan logic.
- Read LDR → print → light on/off.
- Repeat continuously.
