var data; // variable to hold the JSON

function preload() {
    // the URL to Get the data. you need to replace username and feedname with your values
    var url = 'https://io.adafruit.com/api/v2/username/feeds/feedname';

    data = loadJSON(url); // preload the JSON into the data obj before the sketch starts
}

function setup() {
    createCanvas(512, 512);
    frameRate(1); // update once per second
}

function draw() {
    // Draw things    
    background(200);
    fill(0, 102, 153);
    ellipse(width / 2, height - (data.last_value / 2), 20, 20);
    textAlign(LEFT, CENTER);
    text(data.last_value, width / 2 + 15, height - (data.last_value / 2)); // last_value is an attribute in this file that gives most recent update from sensor
}
