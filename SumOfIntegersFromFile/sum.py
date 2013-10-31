# Sum of Integers from File solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

sum = 0
for line in open(sys.argv[1], 'r'):
  sum += int(line)
print sum
