# Pascal's Triangle solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  depth = int(line)
  triangle = "1 "
  previousLine = [1]
  thisLine = []
  for i in range(2, depth + 1):
    triangle += "1 "
    thisLine = [1]
    for j in range(0, len(previousLine) - 1):
      nextVal = previousLine[j] + previousLine[j+1]
      thisLine.append(nextVal)
      triangle += (str(nextVal) + " ")
    triangle += "1 "
    thisLine.append(1)
    previousLine = thisLine

  print (triangle)
