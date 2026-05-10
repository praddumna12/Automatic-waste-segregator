/*
 * Automatic Dry & Wet Waste Segregator
 * Gyan Ganga Institute of Technology and Sciences, Jabalpur
 * Batch: 2023-2027
 *
 * Components:
 *   - Arduino Uno
 *   - Soil Moisture Sensor  -> A0
 *   - Ultrasonic Sensor     -> Trig: 12, Echo: 11
 *   - Servo Motor           -> Pin 8
 *   - I2C LCD 16x2          -> Address 0x27
 *
 * Logic:
 *   1. Ultrasonic sensor detects if waste is placed (distance < 15 cm)
 *   2. Soil moisture sensor reads humidity of the waste
 *   3. If humidity > threshold -> WET  -> servo rotates to 160 degrees
 *      If humidity <= threshold -> DRY -> servo rotates to 20 degrees
 *   4. Servo returns to center (90 degrees) after sorting
 *   5. LCD displays real-time classification status
 */

#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// -- Objects -----------------------------------------------
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo servo1;

// -- Pin Definitions ---------------------------------------
const int trigPin = 12;
const int echoPin = 11;
const int potPin  = A0;

// -- Configuration -----------------------------------------
const int maxDryValue    = 1;   // Humidity % above this = WET waste
const int Ultra_Distance = 15;  // cm - waste detected if closer than this

// -- Variables ---------------------------------------------
long duration;
int  distance = 0;
int  soil     = 0;
int  fsoil    = 0;

// -- Setup -------------------------------------------------
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo1.attach(8);
  servo1.write(90); // Start at center position

  Serial.println("Soil Sensor     Ultrasonic          Servo");
  lcd.print(".........");
  delay(1000);
}

// -- Main Loop ---------------------------------------------
void loop() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Dry Wet Waste");
  lcd.setCursor(3, 1);
  lcd.print("Segregator");

  // Measure distance (average of 2 readings)
  distance = 0;
  for (int i = 0; i < 2; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(7);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);

    duration  = pulseIn(echoPin, HIGH);
    distance += duration * 0.034 / 2;
    delay(10);
  }
  distance = distance / 2;

  // Waste detected within range
  if (distance < Ultra_Distance && distance > 1) {
    delay(1000);

    // Read moisture sensor (average of 3 readings)
    fsoil = 0;
    for (int i = 0; i < 3; i++) {
      soil   = analogRead(potPin);
      soil   = constrain(soil, 485, 1023);
      fsoil += map(soil, 485, 1023, 100, 0);
      delay(75);
    }
    fsoil = fsoil / 3;

    Serial.print("Humidity: ");
    Serial.print(fsoil);
    Serial.print("%");
    Serial.print("    Distance: ");
    Serial.print(distance);
    Serial.print(" cm");

    // Classify and sort
    if (fsoil > maxDryValue) {
      // WET WASTE
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Garbage Detected!");
      lcd.setCursor(6, 1);
      lcd.print("WET");
      Serial.println("     ==> WET Waste");
      servo1.write(160);
      delay(3000);
    } else {
      // DRY WASTE
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Garbage Detected!");
      lcd.setCursor(6, 1);
      lcd.print("DRY");
      Serial.println("     ==> DRY Waste");
      servo1.write(20);
      delay(3000);
    }

    servo1.write(90); // Return servo to center
  }

  // Reset for next cycle
  distance = 0;
  fsoil    = 0;
  delay(1000);
}
