// this works by automagically adding NULL at end of array.
char myUndefString[] = "scott"; // creates an array of type char

// this will work
char myString[5] = "scott"; // creates an array of type char

// but this is a "better way
char myStringTerm[6] = "scott"; // creates an array of type char

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ;;
  }

  Serial.print("Size of myUndefString[] : ");
  Serial.println(sizeof(myUndefString));
  Serial.print("myUndefString[] contents : ");
  for (int x = 0; x < sizeof(myUndefString); x++) {
    Serial.print(myUndefString[x]);
  }

  Serial.print('\n');
  Serial.println("/////////////////");

  Serial.print("Size of myString[] : ");
  Serial.println(sizeof(myString));
  Serial.print("myString[] contents : ");
  for (int x = 0; x < sizeof(myString); x++) {
    Serial.print(myString[x]);
  }

  Serial.print('\n');
  Serial.println("/////////////////");

  Serial.print("Size of myStringTerm[] : ");
  Serial.println(sizeof(myStringTerm));
  Serial.print("myStringTerm[] contents : ");
  for (int x = 0; x < sizeof(myStringTerm); x++) {
    Serial.print(myStringTerm[x]);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
