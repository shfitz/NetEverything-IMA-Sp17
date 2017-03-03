#include <SPI.h>
#include <SD.h>

// if using somethng other than a shield, note the connectiosn
// MOSI = pin 11
// MISO = pin 12
// SCLK = pin 13

// pin 10 is default CS pin, but on the Etheret shield it's attached to pin 4
const int CS_SD = 4;

File dataFile; // file we will open

void setup() {
  Serial.begin(9600); // open serial monitor

  if (!SD.begin(CS_SD)) { // we can check the status of the card
    Serial.println("card failure"); // if issue opening
    return; // break
  }
  Serial.println("card initialized"); // otherwise all is good

  dataFile = SD.open("log.csv", FILE_WRITE); // open a file for writing
  // if the file doesn;t exist, it will be created
  if (dataFile) {  // once open
    dataFile.println("hi!"); // print some data to the card
    dataFile.close(); // close the file to write to it
  } else {
    Serial.println("can't open file"); // report if there's an error
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
