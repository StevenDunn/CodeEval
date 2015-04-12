// Fizz Buzz solution in Node for CodeEval.com by Steven A. Dunn

var fs = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
  if (line !== "") {

    var split = line.split(" ");
    var A = split[0];
    var B = split[1];
    var N = split[2];

    var output = "";
    for (var i = 1; i < parseInt(N) + 1; ++i) 
    {
      var aMod = i % parseInt(A);
      var bMod = i % parseInt(B);

      if (aMod === 0 && bMod === 0)
        output += "FB";
      else if (aMod === 0)
        output += "F";
      else if (bMod === 0)
        output += "B";
      else
        output += i;
      output += " ";
    }
    console.log(output);
  }
});
