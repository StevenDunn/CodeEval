# Decimal to Binary solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  print bin(int(line.strip('\n')))[2:]
