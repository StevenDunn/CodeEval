# Sum of Integers solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  numbers = map(int, line.rstrip('\n').split(','))

  # Kadane's Algorithm
  maxEndingHere = 0
  maxSoFar = 0
  for i in range(0, len(numbers)):
    maxEndingHere = max(0, maxEndingHere + numbers[i])
    maxSoFar = max(maxSoFar, maxEndingHere)
  print maxSoFar
