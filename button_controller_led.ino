/*
  Button-Controlled LED Sequencer
  -------------------------------
  This sketch demonstrates a simple LED sequencing mechanism using a single button.
  Each press cycles through three LEDs, lighting one at a time in sequence.

  Components:
    - Pushbutton connected to digital pin 2 (with internal pull-up enabled)
    - Three LEDs connected to digital pins 9, 10, and 11 through resistors

  Functionality:
    - On each button press, turn off all LEDs and light up the next one in sequence
    - Uses internal pull-up, so the button connects to GND when pressed
    - Debouncing is handled with a short delay after press detection
*/

int reading;
int lastReading = HIGH;
int count;

void setup()
{
  pinMode(2, INPUT_PULLUP); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  count = 0;

  digitalWrite(9 + (count % 3), HIGH); // Turn on first LED
}

void loop()
{
  reading = digitalRead(2);

  if (reading == LOW && lastReading == HIGH) 
  {
    Serial.println("Button pressed!!!");

    // Turn off all LEDs
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);

    // Increment counter and light up the next LED
    count++;
    digitalWrite(9 + (count % 3), HIGH); 

    delay(200); // Simple debounce delay
  }

  lastReading = reading;
}
