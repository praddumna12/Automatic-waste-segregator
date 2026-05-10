# Automatic Dry & Wet Waste Segregator 🗑️

An IoT-based automated waste segregation system built using Arduino Uno that classifies waste as **dry or wet** and physically sorts it into the correct bin using a servo motor — reducing manual effort and improving recycling efficiency.

---

## Problem Statement

Improper waste disposal leads to land pollution, health hazards, and environmental degradation. Most waste management systems lack proper segregation at the source — mixing dry and wet waste in landfills makes recycling inefficient and increases methane emissions.

This project automates waste classification to promote organized, eco-friendly waste management.

---

## How It Works

1. Waste is placed into the input chamber
2. The **Ultrasonic Sensor** detects the presence of waste (distance < 15 cm)
3. The **Soil Moisture Sensor** reads whether the waste is wet or dry
4. Based on the reading:
   - **Wet waste** → Servo motor rotates to 160° → directs to **wet bin**
   - **Dry waste** → Servo motor rotates to 20° → directs to **dry bin**
5. Servo returns to center (90°) after sorting
6. The **I2C LCD Display** shows real-time classification status

---

## Components Used

| Component | Pin | Purpose |
|---|---|---|
| Arduino Uno | — | Main microcontroller |
| Soil Moisture Sensor | A0 | Detects moisture to classify wet waste |
| Ultrasonic Sensor (HC-SR04) | Trig: 12, Echo: 11 | Detects presence of waste |
| Servo Motor (9g) | Pin 8 | Physically sorts waste into correct bin |
| I2C LCD 16x2 | SDA: A4, SCL: A5 | Shows real-time system status |

**Total Cost: Rs. 1000/-**

---

## Libraries Required

- `LiquidCrystal_I2C` — included in this repo
- `Servo` — included in this repo

Install via Arduino IDE: Sketch → Include Library → Add .ZIP Library

---

## Results

| Function | Status |
|---|---|
| Waste Detection | Achieved – Approximately Accurate |
| Waste Segregation | Achieved – Accurately |
