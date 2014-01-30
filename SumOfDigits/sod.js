// Sum of Digits soln in Node for CodeEval.com by Steven A. Dunn

var fs = require("fs");

fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
  if (line !== "") {
    var sum = 0;
    for (var c = 0; c < line.length; ++c)
      sum += parseInt(line[c]);
    console.log(sum);
  }
});
