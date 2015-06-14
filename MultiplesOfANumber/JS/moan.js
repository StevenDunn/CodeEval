// Multiples of a Number soln in Node for CodeEval.com by Steven A. Dunn
var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function(line) {
  if (line !== "") {
    line = line.split(",");
    var x = parseInt(line[0]);
    var n = parseInt(line[1]);

    var multiple = 2;
    var multipleN = n;

    while (x > multipleN) {
      multipleN = n * multiple;
      multiple += 1;
    }

    console.log(multipleN);
  }
});
