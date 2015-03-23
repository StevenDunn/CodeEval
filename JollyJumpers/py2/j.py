# Jolly Jumpers solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = map(int, line.rstrip('\n').split(' '))
  N = line[0]
  numbers = line[1:]
  abs_diffs = []
  for i in range(0, N - 1):
    abs_diffs.append(abs(numbers[i] - numbers[i + 1]))
  abs_diffs.sort()
  not_jolly = False
  for i in range(0, N-2):
    if abs_diffs[i] == 0 or abs_diffs[i+1] > abs_diffs[i] + 1:
      not_jolly = True
      break
  if not_jolly:
    print "Not jolly"
  else:
    print "Jolly"