// simple serial
// send one sesnor from arduino to processing
const int sensePin = A0;    // sensor to control red color

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(sensePin));
  delay(16); // let's let processing breathe, ok?
}
