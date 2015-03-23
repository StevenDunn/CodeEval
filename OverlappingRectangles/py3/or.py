# Overlapping Rectangles solution in Python 3 for CodeEval.com by Steven A. Dunn

def isOverlap(a1, a2, b1, b2):
  if a1 > a2: a1, a2 = a2, a1
  if b1 > b2: b1, b2 = b2, b1

  overlap = False
  for i in range(a1, a2+1):
    if i >= b1 and i <= b2: overlap = True
  return overlap

import sys

for line in open(sys.argv[1], 'r'):
  line = list(map(int, line.rstrip('\n').split(',')))
  if isOverlap(line[0], line[2], line[4], line[6]) and isOverlap(line[1], line[3], line[5], line[7]): print (True)
  else: print (False)
