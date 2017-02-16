// send multiple bytes to processing with ASCII
// using call and response

const int potPin = A0;    // sensor to control size
const int switch1Pin = 2;  // switch for bg color
const int switch2Pin = 3;   // switch for circle color

int inByte = 0;         // incoming serial byte

void setup() {
  Serial.begin(9600); // start serial communication
  pinMode(switch1Pin, INPUT);
  pinMode(switch2Pin, INPUT );

  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  // if we get a byte from processing, read sensors :
  if (Serial.available() > 0) {
    // get incoming byte (Note that we do nothing with it)
    inByte = Serial.read();

    Serial.print(digitalRead(switch1Pin)); // send val
    Serial.print(",");
    Serial.print(digitalRead(switch2Pin)); // send ther val
    Serial.print(",");
    Serial.println(analogRead(potPin)); // send 3rd val with NL & CR
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0,0");   // send a string to prime the pump
    delay(300); // when something appears in the buffer, we escape this loop
  }
}
