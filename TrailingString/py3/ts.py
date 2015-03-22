# Trailing String solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(',')
  if line[0][-len(line[1]):] == line[1]: print (1)
  else: print (0)
