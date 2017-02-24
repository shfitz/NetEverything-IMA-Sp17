#include <SoftwareSerial.h>
// RX = digital pin 10, TX = digital pin 11
SoftwareSerial btPort(10, 11);

void setup() {
  // Open serial communication with Arduino
  Serial.begin(9600);

  // Start the software serial port
  btPort.begin(38400);
}

void loop() {

  // while there is data coming in from the modem, read it
  // and send to the hardware serial port:
  while (btPort.available() > 0) {
    char inByte = btPort.read();
    Serial.write(inByte);
  }

  // while there is data coming in to the Arduino, read it
  // and send to the bt modem serial:
  while (Serial.available() > 0) {
    char inByte = Serial.read();
    btPort.write(inByte);
  }
}






