# Jolly Jumpers solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = list(map(int, line.rstrip('\n').split(' ')))
  N = line[0]
  numbers = line[1:]

  abs_diffs = 0
  for i in range(0, N - 1):
    abs_diffs += abs(numbers[i] - numbers[i + 1])

  jj_sum = (N * (N - 1))/ 2

  if abs_diffs == jj_sum:
    print ("Jolly")
  else:
    print ("Not jolly")
