# Valid Parentheses solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n')
  parenStack = []
  result = True
  for c in line:
    if c == '(': parenStack.append(')')
    elif c == '[': parenStack.append(']')
    elif c == '{': parenStack.append('}')
    elif c == ')' or c == ']' or c == '}':
      if parenStack:
        paren = parenStack.pop()
        if not c == paren: result = False
      else: result = False
  if parenStack: result = False
  print (result)
