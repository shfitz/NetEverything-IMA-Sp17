void setup() {
  Serial.begin(9600);
  
  String myName = "Scott";
  
  Serial.print("myName is ");
  Serial.println(myName);

  // how long
  Serial.print("Length of myName : ");
  Serial.println(myName.length());

  // add things to the end of the String
  myName.concat(" likes Fatty and Weirdo");
  Serial.print("Name : ");
  Serial.println(myName);

  // how long now?
  Serial.print("myName is now : ");
  Serial.println(myName.length());

  // Alternative way of adding text
  myName = "Scott"; // reset to original text
  Serial.print("myName :  ");
  Serial.println(myName);

  myName += " had 2 cats";
  myName = myName + ", they were Fatty " + " and Weirdo";
  Serial.print("myName : ");
  Serial.println(myName);

  // this won't work with arrays
  myName = "A large number is: ";
  myName = myName + 32768;
  Serial.print("myName :  ");
  int myVal = 10053;
  Serial.println(myName + " hello " + String(myVal));
}

void loop() {
  // leave empty for now
}
