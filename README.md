# Embedded-System-for-Air-Quality-Monitoring-and-Automated-Home-Control
an embedded system designed for air quality monitoring and automated home control uses an MQ-2 gas sensor to detect harmful gases and an LDR to measure ambient light levels. When gas concentration exceeds a safe threshold, the system activates a ventilation fan and flashes alert LEDs.
 ![image_alt](https://github.com/ankesha777/Embedded-System-for-Air-Quality-Monitoring-and-Automated-Home-Control/blob/7074ff11375857cac156d471f5273b6102a79732/Image.jpg)

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

# System Design
The system is based on a sensor-actuator model:
1. Gas Detection Subsystem
- The MQ-2 sensor outputs an analog voltage proportional to gas concentration.
- The microcontroller reads the voltage via the ADC and compares it with a safety threshold.
- If the reading exceeds the danger limit, LEDs flash to warn the user, and the fan is activated.

2. Fan Control Subsystem
- Controlled through a motor driver, the fan runs at a fixed speed when gas concentration exceeds a set value.
- Direction control pins ensure correct airflow for ventilation.

3. Lighting Control Subsystem
- An LDR measures light levels using a voltage divider.
- When the light level falls below a set threshold, the microcontroller activates the lighting LED.

# Working Principle
The microcontroller continuously samples sensor data:
1. Gas Level Monitoring
- If gasValue > 150, gas alert LEDs blink rapidly.
- If gasValue > 100, the fan turns on automatically.
2. Lighting Control
- If ldrValue < 1000, lighting LED turns on; otherwise, it remains off.
The system operates in real time, responding immediately to environmental changes.
  
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

# Applications
- Home safety systems (gas leak detection).
- Energy-efficient home lighting.
- Industrial workshop ventilation control.
- Integration into IoT-based smart homes.

# Advantages
- Low-cost and easy to assemble.
- Fully automated — no manual operation required.
- Scalable — more sensors or relays can be added.
- Improves safety and energy efficiency.

# Results
- System flashes alerts when gas spikes above the alert threshold.
- Fan engages automatically at elevated gas readings and helps reduce the level.
- Lighting follows ambient brightness, improving energy efficiency.

# Future Enhancements
- Add Wi-Fi module (ESP8266) for IoT-based remote monitoring.
- Make fan speed proportional to gas level for efficiency.
- Replace LEDs with high-power light control via relays.
- Integrate more sensors (temperature, humidity, CO₂).

# Conclusion
This project successfully demonstrates a robust embedded system capable of environment monitoring and automated control.It integrates multiple sensors and actuators to create a responsive home safety and automation solution. With minor upgrades, it can be adapted into a complete IoT smart home device.
