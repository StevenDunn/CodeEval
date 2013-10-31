# Sum of Digits solution in Python 2 for CodeEval.com by Steven A. Dunn

def sumOfDigits(n):
  sum = 0
  for c in n:
    sum += int(c)
  return sum

import sys

for line in open(sys.argv[1], 'r'):
  print sumOfDigits(line.strip())
