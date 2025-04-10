/*
  Temperature-based RGB LED Indicator using DHT11 Sensor
  ------------------------------------------------------
  This sketch reads temperature from a DHT11 sensor and uses an RGB LED
  to visually indicate the temperature range:

    - Green  : Below 22°C
    - Yellow : Between 22°C and 26°C
    - Red    : Above 26°C

  Connections:
    - DHT11 data pin -> Digital pin 4
    - RGB LED (via resistors):
        - Red   -> Pin 5
        - Green -> Pin 6
        - Blue  -> Pin 11
*/

#define LEDR 5
#define LEDG 6
#define LEDB 11

#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  Serial.print("Temperatura: ");
  Serial.println(t);

  if (isnan(t)) {
    // If the temperature reading failed, turn off the LED
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 0);
    analogWrite(LEDB, 0);
    return;
  }

  if (t < 22) {
    // Green
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 255);
    analogWrite(LEDB, 0);
  } else if (t >= 22 && t <= 26) {
    // Yellow = Red + Green
    analogWrite(LEDR, 255);
    analogWrite(LEDG, 255);
    analogWrite(LEDB, 0);
  } else {
    // Red
    analogWrite(LEDR, 255);
    analogWrite(LEDG, 0);
    analogWrite(LEDB, 0);
  }

  delay(5000); // Wait 5 seconds before reading again
}
