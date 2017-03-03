// this works by automagically adding NULL at end of array.
char myUndefString[] = "scott"; // creates an array of type char

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // what's in there now
  Serial.println(myUndefString[0]);

  // can't use double quotes, it will compile, but make thisg wonky
  myUndefString[0] = "S";
  Serial.println(myUndefString[0]);
  
  // this works though
  myUndefString[0] = 'S';
  Serial.println(myUndefString[0]);
}

void loop() {
  // put your main code here, to run repeatedly:

}
