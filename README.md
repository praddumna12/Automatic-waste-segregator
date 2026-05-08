# Automatic Dry & Wet Waste Segregator 🗑️

An IoT-based automated waste segregation system built using Arduino Uno that classifies waste as **dry or wet** and physically sorts it into the correct bin using a servo motor — reducing manual effort and improving recycling efficiency.

---

## 🔧 Problem Statement

Improper waste disposal leads to land pollution, health hazards, and environmental degradation.Most waste management systems lack proper segregation at the source — mixing dry and wet waste in landfills makes recycling inefficient and increases methane emissions.

This project automates waste classification to promote organized, eco-friendly waste management.

---

## ⚙️ How It Works

1. Waste is placed into the input chamber
2. The **Ultrasonic Sensor** detects the presence of waste
3. The **Soil Moisture Sensor** reads whether the waste is wet or dry
4. Based on the reading:
   - **Wet waste** → Servo motor rotates to direct waste into the **green (wet) bin**
   - **Dry waste** → Servo motor rotates to direct waste into the **blue (dry) bin**
5. The **I2C LCD Display** shows the real-time classification status

---

## 🛠️ Components Used

| Component | Purpose | 
|---|---|
| Arduino Uno  | Main microcontroller | 
| Soil Moisture Sensor | Detects moisture to classify wet waste |
| Ultrasonic Sensor (HC-SR04) | Detects presence of waste in the chamber |
| Servo Motor (9g) | Physically sorts waste into correct bin |
| I2C LCD Display | Shows real-time system status |
| Jumper Wires | Electrical connections between components |

**Approx Cost: Rs. 1000/-**

---

## ✅ Results

| Function | Status |
|---|---|
| Waste Detection | ✅ Achieved – Approximately Accurate |
| Waste Segregation | ✅ Achieved – Accurately |
