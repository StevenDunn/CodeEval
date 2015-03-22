# Sum of Integers solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  numbers = list(map(int, line.rstrip('\n').split(',')))

  # Kadane's Algorithm
  maxEndingHere = maxSoFar = numbers[0]
  for x in numbers[1:]:
    maxEndingHere = max(x, maxEndingHere + x)
    maxSoFar = max(maxSoFar, maxEndingHere)
  print (maxSoFar)
