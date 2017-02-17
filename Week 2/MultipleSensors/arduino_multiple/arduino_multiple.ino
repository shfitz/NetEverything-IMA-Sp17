// send multiple sesnors to processing with ASCII

const int potPin = A0;    // sensor to control size
const int switch1Pin = 2;  // switch for bg color
const int switch2Pin = 3;   // switch for circle color

void setup() {
  Serial.begin(9600); // start serial communication
  pinMode(switch1Pin, INPUT);
  pinMode(switch2Pin, INPUT );
}

void loop() {
  Serial.print(digitalRead(switch1Pin)); // send val
  Serial.print(",");
  Serial.print(digitalRead(switch2Pin)); // send ther val
  Serial.print(",");
  Serial.println(analogRead(potPin)); // send 3rd val with NL & CR
  delay(16); // let it breathe
}
