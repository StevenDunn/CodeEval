# Armstrong Numbers solution in Python 2 for CodeEval.com by Steven A. Dunn

def isArmstrong(N):
  sum = 0
  numDigits = len(N)
  for c in N:
    sum += (int(c) ** numDigits) 
  if sum == int(N): return True
  return False

import sys

for line in open(sys.argv[1], 'r'):
  if isArmstrong(line.rstrip('\n')): print True
  else: print False
