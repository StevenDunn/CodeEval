# Simple Sorting solution in Python for CodeEval.com by Steven A. Dunn

import sys
from decimal import Decimal

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  line = map(Decimal, line)
  line.sort()
  line = map(str, line)
  for i in line:
    sys.stdout.write("%s " % i),
  print
