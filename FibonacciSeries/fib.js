// Fib seq soln in Node for CodeEval.com by Steven A. Dunn

var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
  if (line !== "") {
    var n = parseInt(line);
    var buf1 = 1;
    var buf2 = 1;
    var temp = 0;

    if (n === 0) console.log(0);
    else if (n == 1 || n == 2) console.log(1);
    else {
      for (var fibIdx = 3; fibIdx <= n; ++fibIdx) {
        temp = buf1;
        buf1 = buf2;
        buf2 = buf1 + temp;
      }  
      console.log(buf2);
    }
  }
});
