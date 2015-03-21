# Stack Implementation solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  stack = []
  for i in line:
    stack.append(i)
  while stack:
    print (stack.pop(), end=" ")
    try:
      stack.pop()
    except IndexError:
      break
  print()
