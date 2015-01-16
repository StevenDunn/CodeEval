# Multiplication Tables solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for i in range(1,13):
  for j in range(1,13):
    if j == 1: sys.stdout.write("%2d" % (i * j))
    else: sys.stdout.write("%4d" % (i * j))
  print
  
