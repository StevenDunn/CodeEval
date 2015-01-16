# Fizz Buzz solution written in Python for CodeEval.com by Steven A. Dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
  A, B, N = line.split()
  output = ""
  for i in range(1, int(N) + 1):
    aMod = i % int(A)
    bMod = i % int(B)
    if(aMod == 0 and bMod == 0):
      output += "FB"
    elif(aMod == 0):
      output += "F"
    elif(bMod == 0):
      output += "B"
    else:
      output += str(i)
    output += " ";
  print(output)
f.close()