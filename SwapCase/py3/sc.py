# Swap Case solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  print (line.swapcase(), end=" ")
