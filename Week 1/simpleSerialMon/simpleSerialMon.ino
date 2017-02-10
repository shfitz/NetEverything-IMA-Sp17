int ledPin = 3;
int fade = 0;
int potPin = A0;
int potVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  delay(1);
  fade = potVal/4;
  analogWrite(ledPin, fade);
  Serial.print("PotVal : ");
  Serial.print(potVal);
  Serial.print(", ledVal : ");
  Serial.println(fade);
}
