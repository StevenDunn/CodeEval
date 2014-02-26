# Split the number soln in Python for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  expr = line.rstrip('\n').split(' ')
  expr[0] = list(expr[0])

  for i in range(0, len(expr[1])):
    if expr[1][i] == '+':
      expr[0].insert(i, '+')
    elif expr[1][i] == '-':
      expr[0].insert(i, '-')
    else:
      continue
  
  result = ''.join(expr[0])

  print eval(result)
