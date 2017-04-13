// simple node server

// include libraries and declare global variables:

var express = require('express');   // include the express library 
                                    // you'll need to install this via npm
var server = express();             // create a server using express

// define the callback function that's called when the server gets a request

function respondToClient(request, response) {
    console.log("there's an incoming request!!!!"); // make a note in the terminal
    // send the folllowing to the client:
    response.writeHead(200, {"Content-Type": "text/html"});
    response.write("Hello friend");
//    response.write("< " + new Date() + ">");
    response.end();
}

// main program

// start a server on port 8080: 
server.listen(8080);

// define what to do when the client requests something: 
server.get('/*', respondToClient);  // when the server gets anything on port 8080
                                    // respond with the rep to client funtion
console.log("Server is listening on port 8080"); // status