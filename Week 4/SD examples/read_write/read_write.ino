#include <SPI.h>
#include <SD.h>

int refresh = 5000; // time in ms to reas sensor

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the time file for reading:
  File timeFile = SD.open("time.txt");
  if (timeFile) {

    // read from the file and store:
    while (timeFile.available()) {
      refresh = timeFile.parseInt();
    }
    // close the file:
    timeFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening time.txt");
  }
}

void loop() {

  // let's create a local timestamp
  long timeStamp = millis();

  File dataFile = SD.open("log.csv", FILE_WRITE); // write to the file when opened
  if (dataFile) {
    dataFile.print(timeStamp);
    dataFile.print(",");
    dataFile.println(analogRead(A0));
    dataFile.close();

    // debug
    Serial.print(timeStamp);
    Serial.print(",");
    Serial.println(analogRead(A0));
  } else {
    Serial.println("Issue with DataFile");
  }
  delay(refresh);
}


