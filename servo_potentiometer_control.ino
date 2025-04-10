/*
  Servo Motor Control with Potentiometer
  --------------------------------------
  This sketch reads the analog value from a potentiometer and maps it
  to control the angle of a servo motor between 0 and 180 degrees.

  Components:
    - Potentiometer connected to analog pin A0
    - Servo motor signal wire connected to digital pin 9

  How it works:
    - The potentiometer value (0–1023) is read via analog input.
    - This value is mapped to an angle (0–180°).
    - The servo rotates to the corresponding angle.
    - Serial output shows the raw value and mapped angle.
*/

#include <Servo.h>

Servo myServo;
const int potPin = A0;
int potValue;
int angle;

void setup() {
  myServo.attach(9);           // Attach servo to pin 9
  Serial.begin(9600);          // Start serial communication
}

void loop() {
  potValue = analogRead(potPin);                // Read potentiometer value (0–1023)
  angle = map(potValue, 0, 1023, 0, 180);        // Map to servo angle (0–180)

  myServo.write(angle);                         // Move servo to angle

  // Print debug info to Serial Monitor
  Serial.print("Valoare Potentiometru: ");
  Serial.print(potValue);
  Serial.print(" -> Unghi: ");
  Serial.println(angle);

  delay(15);  // Short delay for stability
}
