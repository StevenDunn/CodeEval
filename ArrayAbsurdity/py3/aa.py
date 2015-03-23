# Array Absurdity solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  numbers = line.rstrip('\n').split(';')[1].split(',')
  for i in numbers:
    if numbers.count(i) > 1:
      print (i)
      break
