var http = require("http");

var options = {
  "method": "GET",
  "hostname": "127.0.0.1",
  "port": "8360",
  "path": "/control/allRoom",
  "headers": {
    "cache-control": "no-cache",
    "postman-token": "1d853933-f47a-197e-6348-8dd625ca1dac"
  }
};

var req = http.request(options, function (res) {
  var chunks = [];

  res.on("data", function (chunk) {
    chunks.push(chunk);
  });

  res.on("end", function () {
    var body = Buffer.concat(chunks);
    console.log(body.toString());
  });
});

req.end();