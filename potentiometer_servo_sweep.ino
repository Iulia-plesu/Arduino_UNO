/*
  Potentiometer-Controlled Servo Sweep
  ------------------------------------
  This example demonstrates how to control a servo motor using a potentiometer.
  The potentiometer's analog value (0–1023) is read and mapped to a corresponding
  servo angle (0–180 degrees), allowing smooth manual control.

  Components:
    - Potentiometer connected to analog pin A0
    - Servo motor signal connected to digital pin 9

  Functionality:
    - Rotate the potentiometer to change the servo's angle
    - Serial monitor prints both the raw and mapped values
*/

#include <Servo.h>

Servo myServo;
const int potPin = A0;  // Analog pin connected to potentiometer
int potValue;
int angle;

void setup() {
  myServo.attach(9);     // Attach servo motor to pin 9
  Serial.begin(9600);    // Start serial communication
}

void loop() {
  potValue = analogRead(potPin);                 // Read potentiometer value
  angle = map(potValue, 0, 1023, 0, 180);        // Convert to angle

  myServo.write(angle);                          // Move servo

  // Print values to Serial Monitor
  Serial.print("Valoare Potentiometru: ");
  Serial.print(potValue);
  Serial.print(" -> Unghi: ");
  Serial.println(angle);

  delay(15);  // Small delay for smooth movement
}
