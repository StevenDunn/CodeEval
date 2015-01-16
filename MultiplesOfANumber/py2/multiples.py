# Multiples of a Number solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
  x, n = line.split(',')
  x = int(x)
  n = int(n)

  multiple = 2
  multipleN = n
  while x >= multipleN:
    multipleN = n * multiple
    multiple += 1
  print multipleN
