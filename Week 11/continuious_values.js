var data; // variable to hold the JSON// the URL to Get the data. you need to replace username and feedname with your values
var url = 'https://io.adafruit.com/api/v2/username/feeds/feedName/data?limit=10';

function preload() {
    data = loadJSON(url);       // preload the JSON into the data obj before the sketch starts
}

function setup() {
    createCanvas(512, 512);
    frameRate(1); // update once per second
}

function draw() {
    
    data = loadJSON(url, renderGraph); // after a new URL is loaded, render the graph
}

function renderGraph() {
    // Draw things
    background(0);
    noFill();
    stroke(255);
    textAlign();
    
    text(data[0].created_at, width/2, 30); // created_at is an attribute in this file that gives most recent update from sensor

    textAlign(CENTER, BASELINE);
    
    for (var i = 9; i >= 0; i--) {
        ellipse((i * 51)+20, height - (data[i].value / 2), 5, 5); // value is an attribute in this file that gives most  updates from sensor
 
        text(data[i].value, (i * 51)+20, (height - (data[i].value / 2))-10 );
        if (i > 0) {
            line((i * 51)+20, height - (data[i].value / 2), ((i-1) * 51)+20, height - (data[i - 1].value / 2));
        }
    }
}
