# Lowercase solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
  print line.lower(),
f.close()
