# Bit Positions solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
  n, pos1, pos2 = line.split(',')
  b = bin(int(n))
  if b[-int(pos1)] == b[-int(pos2)]:
    print "true"
  else:
    print "false"
f.close()
