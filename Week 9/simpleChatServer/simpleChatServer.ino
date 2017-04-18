/*
  based on Chat Server example at
  https://www.arduino.cc/en/Tutorial/ChatServer
*/

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0x12, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);

// telnet defaults to port 23
EthernetServer server(23);

boolean alreadyConnected = false; // whether or not the client was connected previously

void setup() {
  // initialize the ethernet device
  Ethernet.begin(mac, ip);
  // start listening for clients
  server.begin();
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("Chat server address:");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // wait for a new client:
  EthernetClient client = server.available();

  // when the client sends the first byte, say hello:
  while (client) {
    if (!alreadyConnected) {
      // clear out the input buffer:
      client.flush();
      Serial.println("We have a new client");
      client.println("Hello, client!");
      alreadyConnected = true;
    }

    if (client.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = client.read();
      // write bytes to the serial monitor:
      Serial.write(thisChar);
    }

    if (Serial.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = Serial.read();
      // send the bytes to the client :
      server.write(thisChar);
      // echo the bytes to the serial monitor:
      Serial.write(thisChar);
    }

    if (!client.connected()) { // if we have no client
      client.stop(); // kill the connection with fire
      Serial.println("client disconnected");
      alreadyConnected = false; // no connection present
    }
  }

}
