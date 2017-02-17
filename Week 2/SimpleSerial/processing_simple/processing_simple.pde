import processing.serial.*;   // import serial lib

float sensorValue = 0;   // value from Arduino

Serial myPort; // create instance of serial lib

void setup() {
  size(512, 512); // size of the sketch

  println(Serial.list()); // list all the serial ports on this computer
  // NB : you must have your Arduino connected when you first run this to figure out what 
  // port it is attached to!!

  myPort = new Serial(this, Serial.list()[3], 9600); // instatiate the object
  // new serial object (named "myPort") that will run in this" sketch, which is physicallon on port X
  // and communicates at 9600 baud

  // generate a serialEvent() when you get a newline character:
  myPort.bufferUntil('\n');
}

void draw() {
  // set the background color and size of the sphere:
  background(sensorValue/4);
  fill(255- sensorValue/4);
  ellipse(width/2, height/2, sensorValue/2, sensorValue/2); 
}

void serialEvent(Serial myPort) {

  // get the ASCII string by reading from the port until a newline char is reached
  String inString = myPort.readStringUntil('\n');

  if (inString != null) { // if you have stuff in the string
    // trim off any whitespace:
    inString = trim(inString);
    // convert to float and use in the sketch
    sensorValue = float(inString); 
  }
}