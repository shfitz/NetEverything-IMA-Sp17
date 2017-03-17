const int myID = 2;  // A number to ID this Arduino to central 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  // Wait until we receive a byte from the central XBee device
  if (Serial.available()) {
    int throwaway = Serial.read(); // read the byte and discard it
    Serial.print(myID); // send my ID number
    Serial.print(",");
    Serial.println(analogRead(A0)); // send data
  }
}
