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
  fade = map(potVal, 470, 870, 0, 255);
  fade = constrain(fade, 0, 255);
  analogWrite(ledPin, fade);
  Serial.print("sensorVal : ");
  Serial.print(potVal);
  Serial.print(", ledVal : ");
  Serial.println(fade);
}
