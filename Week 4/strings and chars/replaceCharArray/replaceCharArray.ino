char myName[] = "Scott"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(myName);

  myName[0] = 'A';
  myName[1] = 'n';
  myName[2] = 'd';
  myName[3] = 'y';
  myName[4] = 0;

  Serial.println(myName);
}

void loop() {
  // put your main code here, to run repeatedly:

}
