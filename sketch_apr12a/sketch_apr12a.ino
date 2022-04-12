// ATtiny85 Blink!

#define LED_PIN PB0

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(2,LOW);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
