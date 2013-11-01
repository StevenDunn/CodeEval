# Unique Elements solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  vals = line.rstrip('\n').split(',')
  vals = map(int, vals)
  unique = list(set(vals))
  unique.sort() 
  for i in range(0, len(unique) - 1):
    sys.stdout.write("%d," % unique[i]),
  print unique[-1]
