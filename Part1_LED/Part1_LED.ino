/*
  Simple LED Blink
  Connect an LED and resistor to pin 13.
  The LED will turn on and off every few seconds.
  Change blinkDelayMs to adjust how long the LED stays on or off.
*/

const int ledPin = 13;          // pin for the LED
unsigned int blinkDelayMs = 1000; // delay in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);   // LED on
  delay(blinkDelayMs);
  digitalWrite(ledPin, LOW);    // LED off
  delay(blinkDelayMs);
}
