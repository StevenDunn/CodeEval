# Reverse and Add solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  num = int(line)
  iters = 0
  while not str(num) == str(num)[::-1]:
    num += int(str(num)[::-1])
    iters += 1
  print iters, num
