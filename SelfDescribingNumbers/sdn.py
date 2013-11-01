# Self Describing Numbers solution in Python 2 for CodeEval.com by Steven A. Dunn

def isSelfDescribing(n):
  counts = [0] * 10

  for c in n:
    counts[int(c)] += 1

  for i in range(0, len(n)):
    c = int(n[i])
    if not c == counts[i]: return False

  return True;

import sys

for line in open(sys.argv[1], 'r'):
  if isSelfDescribing(line.rstrip('\n')): print 1
  else: print 0
