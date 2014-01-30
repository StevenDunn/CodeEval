// Bit Positions solution in Node for CodeEval.com by Steven A. Dunn

var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
  if (line !== "") {
    line = line.split(",");
    var n = parseInt(line[0]).toString(2);
    var pos1 = parseInt(line[1]);
    var pos2 = parseInt(line[2]);

    if (n.slice(-pos1, -pos1 + 1) == n.slice(-pos2, -pos2 + 1))
      console.log("true");
    else
      console.log("false");
  }
});
