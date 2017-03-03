#include <EEPROM.h>

const int dataPos = 0;
const int namePos = 1;
const int controlNum = 42;

char myName[] = "Ardy";
char yourName[64];

int i;
byte ctrlVal;

void setup() {
  Serial.begin(9600);

  //check to see what's in the EEPROM
  ctrlVal = EEPROM.read(dataPos);

  if (ctrlVal == controlNum) {
    // read the name to greet
    for ( i = 0; i < sizeof(yourName); i++) {
      yourName[i] = EEPROM.read(namePos + i);
    }
    // print out a greeting
    Serial.println("Welcome back!");
    Serial.print("It's good to see you again ");
    Serial.println(yourName);

    // to reset name put 0 back in control byte
    // EEPROM.write(dataPos, 0);
  } else {
    // welcome the new person
    Serial.println("hi, what's your name?");

    // wait for serial data
    while (!Serial.available()) {
      delay(100);
    }

    // Read the data from the buffer
    Serial.readBytes(yourName, Serial.available());

    // say hi
    Serial.print("hi, ");
    Serial.print(yourName);
    Serial.print(". My name is ");
    Serial.println(myName);

    // save name to EEPROM
    for (i = 0; i < sizeof(yourName); i++) {
      EEPROM.write(namePos + i, yourName[i]);
    }

    // now that we have the data, let's write a control value
    EEPROM.write(dataPos, controlNum);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
