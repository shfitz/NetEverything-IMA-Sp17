#include <CurieBLE.h>

BLEPeripheral blePeripheral;  // BLE Peripheral Device (the board you're programming)
BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // BLE LED Service. This is an arbitrary number

// BLE LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEUnsignedCharCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
BLEUnsignedCharCharacteristic fadeCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);

BLECharCharacteristic potCharacteristic("19B10012-E8F2-537E-4F6C-D104768A1216", BLERead | BLENotify); // allows remote device to get notifications

const int ledPin = 13; // pin to use for the LED
const int fadePin = 3; // pin to use for the LED
const int potPin = A0;

void setup() {
  Serial.begin(9600);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);
  pinMode(fadePin, OUTPUT);

  // set advertised local name and service UUID:
  blePeripheral.setLocalName("LED");
  blePeripheral.setAdvertisedServiceUuid(ledService.uuid());

  // add service and characteristic:
  blePeripheral.addAttribute(ledService);
  blePeripheral.addAttribute(fadeCharacteristic);
  blePeripheral.addAttribute(potCharacteristic);

  // set the initial value for the characeristic:
  fadeCharacteristic.setValue(0);
  potCharacteristic.setValue(0);

  // begin advertising BLE service:
  blePeripheral.begin();

  Serial.println("ble device is active, waiting for a connection ... .. . .. . ....");
}

void loop() {
  // listen for BLE peripherals to connect:
  BLECentral central = blePeripheral.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {


      blePeripheral.poll();
      char potVal = analogRead(A0) / 4;
      boolean potChanged = (potCharacteristic.value() != potVal);

      if (potChanged) {
        potCharacteristic.setValue(potVal);
      }

      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
      if (switchCharacteristic.written()) {
        if (switchCharacteristic.value()) {   // any value other than 0
          Serial.println("LED on");
          digitalWrite(ledPin, HIGH);         // will turn the LED on
        } else {                              // a 0 value
          Serial.println(F("LED off"));
          digitalWrite(ledPin, LOW);          // will turn the LED off
        }
      }
      if (fadeCharacteristic.written()) {
        analogWrite(fadePin, fadeCharacteristic.value());
        Serial.println(fadeCharacteristic.value());


      }
    }

    // when the central disconnects, print it out:
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

