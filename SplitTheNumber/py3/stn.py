# Split the number soln in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  nums = line[0]
  expr = line[1]

  operator_index = expr.find('+')
  if operator_index == -1:
    operator_index = expr.find('-')

  num1 = int(nums[0:operator_index])
  num2 = int(nums[operator_index:])

  if expr[operator_index] == '+':
    print (num1 + num2)
  else:
    print (num1 - num2)