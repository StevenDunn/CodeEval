# Minimum Coins solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  total = int(line)
  count = 0
  while total >= 5:
    total -= 5
    count += 1
  while total >= 3:
    total -= 3
    count += 1
  count += total
  print count
