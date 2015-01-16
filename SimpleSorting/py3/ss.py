# Simple Sorting solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys
from decimal import Decimal

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  line = list(map(Decimal, line))
  line.sort()
  line = list(map(str, line))
  for i in line:
    sys.stdout.write("%s " % i),
  print()
