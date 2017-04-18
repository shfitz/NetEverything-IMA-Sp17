// based on https://startingelectronics.org/tutorials/arduino/ethernet-shield-web-server-tutorial/SD-card-web-server-links/

#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

// size of buffer used to capture HTTP requests
#define BUFFER_SIZE   127

// MAC address from Ethernet shield sticker under board
byte mac[] = { 0xDE, 0xAD, 0xAE, 0xEE, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 20);   // IP address, may need to change depending on network
EthernetServer server(80);       // create a server at port 80
File file;                    // handle to files on SD card
char HTTP_request[BUFFER_SIZE] = {0}; // buffered HTTP request stored as null terminated string
char request_index = 0;              // index into HTTP_request buffer

void setup() {
  Serial.begin(9600);       // for debugging

  // initialize SD card
  Serial.println("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("ERROR - SD card initialization failed!");
    return;    // init failed
  }
  Serial.println("SUCCESS - SD card initialized.");
  // check for index.htm file
  if (!SD.exists("index.htm")) {
    Serial.println("ERROR - Can't find index.htm file!");
    return;  // can't find index file
  }
  Serial.println("SUCCESS - Found index.htm file.");

  Ethernet.begin(mac, ip);  // initialize Ethernet device
  server.begin();           // start to listen for clients
}

void loop() {
  EthernetClient client = server.available();  // try to get client

  if (client) {  // got client?
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {   // client data available to read
        char c = client.read(); // read 1 byte (character) from client
        // buffer first part of HTTP request in HTTP_request array (string)
        // leave last element in array as 0 to null terminate string (BUFFER_SIZE - 1)
        if (request_index < (BUFFER_SIZE - 1)) {
          HTTP_request[request_index] = c;          // save HTTP request character
          request_index++;
        }
        Serial.print(c);    // print HTTP request character to serial monitor
        // last line of client request is blank and ends with \n
        // respond to client only after last line received
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connnection: close");
          client.println();
          // open requested web page file
          if (StrContains(HTTP_request, "GET / ") || StrContains(HTTP_request, "GET /index.htm")) {
            file = SD.open("index.htm");        // open web page file
          }
          else if (StrContains(HTTP_request, "GET /page2.htm")) {
            file = SD.open("page2.htm");        // open web page file
          } 
//          else {
//            file = SD.open("404.htm");
//          }
          // send web page to client
          if (file) {
            while (file.available()) {
              client.write(file.read());
            }
            file.close();
          }
          // reset buffer index and all buffer elements to 0
          request_index = 0;
          StrClear(HTTP_request, BUFFER_SIZE);
          break;
        }
        // every line of text received from the client ends with \r\n
        if (c == '\n') {
          // last character on line of received text
          // starting new line with next character read
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // a text character was received from client
          currentLineIsBlank = false;
        }
      } // end if (client.available())
    } // end while (client.connected())
    delay(1);      // give the web browser time to receive the data
    client.stop(); // close the connection
  } // end if (client)
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length) {
  for (int i = 0; i < length; i++) {
    str[i] = 0;
  }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind) {
  char found = 0;
  char index = 0;
  char len;

  len = strlen(str);

  if (strlen(sfind) > len) {
    return 0;
  }
  while (index < len) {
    if (str[index] == sfind[found]) {
      found++;
      if (strlen(sfind) == found) {
        return 1;
      }
    }
    else {
      found = 0;
    }
    index++;
  }
  return 0;
}
