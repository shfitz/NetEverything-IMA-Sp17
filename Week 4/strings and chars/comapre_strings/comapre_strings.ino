char myName[] = "Scott"; // fails because it points to be beginnog of the array, not the whole thing
//String myName = "Scott";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    if (strcmp(myName,"Scott")==0) { // use this if you are comparing a char array. ret 0 if they are the sa

//  if (myName == "Scott") {
    Serial.println("Hi Scott!");
  } else {
    Serial.println("You're not who you think you are");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
