int ledPin = 2;
int period = 250;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(period);

  digitalWrite(ledPin, LOW);
  delay(period);

}
