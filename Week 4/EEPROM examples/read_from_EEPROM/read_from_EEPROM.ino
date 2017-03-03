#include <EEPROM.h>

void setup()
{
  Serial.begin(9600); // open serial port

  byte data = EEPROM.read(0); // read the data from the port
  
  Serial.print("data at position 0:");
  Serial.println(data);

}
void loop() {}
