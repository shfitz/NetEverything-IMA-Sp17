var express = require('express');       // include the express library 
var server = express();                 // create a server using express

// the callback function 
function respondToClient(request, response) {
    // convert the parameters to a string using JSON.stringify: 
    var request = "request: " + JSON.stringify(request.query);
    // write back to the client:
    response.writeHead(200, { // header information
        "Content-Type": "text/html"
    });
    response.write(request); // paramters received
    console.log(request); // local logging is fun
    response.end();
}
// start the server: 
server.listen(8080);
// define what to do when the client requests something: 
server.get('/', respondToClient);
console.log("waiting for connections................");