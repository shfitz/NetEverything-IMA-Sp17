#include <SPI.h>
#include <SD.h>

// if using somethng other than a shield, note the connectiosn
// MOSI = pin 11
// MISO = pin 12
// SCLK = pin 13

// pin 10 is default CS pin, but on the Etheret shield it's attached to pin 4
const int CS_SD = 4;

void setup() {
  Serial.begin(9600); // open serial monitor

  if (!SD.begin(CS_SD)) { // we can check the status of the card
    Serial.println("card failure"); // if issue opening
    return; // break
  }
  Serial.println("card initialized"); // otherwise all is good

}

void loop() {
  // let's create a local timestamp
  long timeStamp = millis();
  
  File dataFile = SD.open("log.csv", FILE_WRITE); // write to the file when opened
  if(dataFile){
    dataFile.print(timeStamp);
    dataFile.print(",");
    dataFile.println(analogRead(A0));
    dataFile.close();

  // debug
    Serial.print(timeStamp);
    Serial.print(",");
    Serial.println(analogRead(A0));   
  } else{
    Serial.println("Issue with DataFile");
  }
  delay(5000);
}
