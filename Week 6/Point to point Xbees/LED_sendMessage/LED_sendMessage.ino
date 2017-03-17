// point to point Xbee sender
// sends data to another arduino 
// that causes the LED attached to pin 13
// to turn on/off

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // start serial

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.write(72); // send a "H" as a byte to turn the remote LED on
  delay(1000);
  Serial.write(76); // send a "L" as a byte to turn the remote LED off
}
