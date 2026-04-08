# Multi-Sensor Control System

## 
This project integrates multiple sensors (temperature, sound, and light) to control a lighting system based on environmental conditions.

---

## Features
- Temperature-based control using LM35
- Clap detection using microphone (edge detection)
- Light detection using LDR
- Threshold-based decision making

---

## Sensors Used

### 🌡️ LM35 (Temperature)
- Analog output (10 mV/°C)
- ADC conversion used to calculate temperature

### 🎤 Microphone
- Detects sound intensity
- Uses edge detection to identify claps

### 💡 LDR (Light Sensor)
- Measures light intensity
- Non-linear response

---

## Key Concept

Temperature calculation:

```T(°C) = ADC_value × 0.488```

Resolution:
≈ 0.49°C per ADC step

---

## ⚠️ Challenges
- Noise in microphone signal
- ADC instability
- Non-linear LDR response

---

## Control Type
Open-loop system (no feedback from output)

---

## Demonstration
https://youtube.com/shorts/CpC9sngDGJo

Developed in 2025
