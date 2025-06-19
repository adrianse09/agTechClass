// Soil Moisture Logger with LEDs
const int sensorPin    = A0;  // analog input
const int ledDryPin    = 2;   // red LED for dry soil
const int ledOkPin     = 3;   // yellow LED for moderate soil
const int ledWetPin    = 4;   // green LED for wet soil

void setup() {
  Serial.begin(9600);                // start serial at 9600 baud
  pinMode(sensorPin, INPUT);
  pinMode(ledDryPin, OUTPUT);
  pinMode(ledOkPin, OUTPUT);
  pinMode(ledWetPin, OUTPUT);
}

void loop() {
  int raw = analogRead(sensorPin);            // 0–1023
  float voltage = raw * (5.0 / 1023.0);       // convert to volts
  // Map raw reading (calibrate dry≈1023, wet≈400) to 0–100%
  int moisturePercent = map(raw, 1023, 400, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  // LED logic
  if (moisturePercent < 30) {
    // too dry
    digitalWrite(ledDryPin, HIGH);
    digitalWrite(ledOkPin,  LOW);
    digitalWrite(ledWetPin, LOW);
  }
  else if (moisturePercent < 60) {
    // moderate
    digitalWrite(ledDryPin, LOW);
    digitalWrite(ledOkPin,  HIGH);
    digitalWrite(ledWetPin, LOW);
  }
  else {
    // sufficiently wet
    digitalWrite(ledDryPin, LOW);
    digitalWrite(ledOkPin,  LOW);
    digitalWrite(ledWetPin, HIGH);
  }

  // Send CSV: <ms since start>,<raw>,<percent>
  unsigned long t = millis();
  Serial.print(t);
  Serial.print(',');
  Serial.print(raw);
  Serial.print(',');
  Serial.println(moisturePercent);

  delay(1000);  // one reading per second
}
