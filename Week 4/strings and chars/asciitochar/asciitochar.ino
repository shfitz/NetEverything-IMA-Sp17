void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:
  char myArray[] = " "; // sets aside memory for a char array

  for (byte x = 32; x < 90; x++) {
    myArray[0] = x;
    Serial.println(myArray[0]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
