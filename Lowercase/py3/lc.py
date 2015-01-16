# Lowercase solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
  print (line.lower(), end=" ")
f.close()
