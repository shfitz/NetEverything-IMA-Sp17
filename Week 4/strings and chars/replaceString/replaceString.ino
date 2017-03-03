String myName = "scott";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("myString : ");
  Serial.println(myName);

  myName = "Andy";

  Serial.print("myString : ");
  Serial.println(myName);

}

void loop() {
  // put your main code here, to run repeatedly:

}
