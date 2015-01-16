# Happy Numbers solution in Python 2 for CodeEval.com by Steven A. Dunn

def isHappy(n, visited):
  sum = 0
  for c in n:
    sum += int(c) * int(c)

  if sum == 1: return True
  if sum in visited: return False;
  visited.append(sum)

  if isHappy(str(sum), visited): return True;
  return False;

import sys

for line in open(sys.argv[1], 'r'):
  visited = list()
  if isHappy(line.rstrip('\n'), visited): print 1
  else: print 0
