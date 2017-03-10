import processing.serial.*;   // import serial lib

Serial myPort; // create instance of serial lib
String inBuffer = " "; // string to hold the tag val

void setup() {
  size(512, 512); // size of the sketch
  frameRate(10);
  println(Serial.list()); // list all the serial ports on this computer

  myPort = new Serial(this, Serial.list()[2], 9600); // instatiate the object
}

void draw() {
  
  if (inBuffer != " ") { // if there's a valid tag
    drawTag(inBuffer);
  }
  
}

void serialEvent(Serial myPort) {
  while (myPort.available() > 13) { // read the values from the tag
    inBuffer = myPort.readString();   
    inBuffer = inBuffer.trim();
    if (inBuffer != null) {
      println(inBuffer);  // print the value to the console
    }
  }
}

void drawTag(String tagVal) {

  background(0);
  
  if (tagVal.equals("180026358A81")) {
    fill(0, 0, 255);
    ellipse(width/2, height/2, 100, 100);
  }
  if (tagVal.equals("010017BA77DB")) {
    fill(255, 0, 0);
    ellipse(width/2, height/2, 100, 100);
  }
  if (tagVal.equals("0000ACB7C6DD")) {
    fill(255, 255, 0);
    ellipse(width/2, height/2, 100, 100);
  }
  inBuffer = " ";
}