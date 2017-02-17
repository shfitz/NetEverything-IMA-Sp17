import processing.serial.*;   // import serial lib

float[] sensorValues = {0, 0, 0};   // array to store values from Arduino

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
  background(255-sensorValues[0]*255);
  fill(sensorValues[1]*255);
  ellipse(width/2, height/2, sensorValues[2]/2+1, sensorValues[2]/2+1); 
  // adding the +1 here to avoid divide by 0 nonsense when there's nothing coming in
}

// serialEvent  method is run automatically by the Processing applet
// whenever the buffer reaches the  byte value set in the bufferUntil()
// method in the setup():

void serialEvent(Serial myPort) {
  // the first couple things we read will be 0,0,0
  // after that we're golden

   // get the ASCII string by reading from the port until a newline char is reached
  String inString = myPort.readStringUntil('\n');

  if (inString != null) { // if you have stuff in the string
    // trim off any whitespace:
    inString = trim(inString);

    // split the string at the commas and convert the
    // resulting substrings into your array:
    sensorValues = float(split(inString, ","));
  }
  
  // print out the values you got:
    for (int sensorNum = 0; sensorNum < sensorValues.length; sensorNum++) {
      print("Sensor " + sensorNum + ": " + sensorValues[sensorNum] + "\t");
    }
    // add a linefeed after all the sensor values are printed:
    println();
    
    // send a byte to ask for more data:
    myPort.write("A");
  }