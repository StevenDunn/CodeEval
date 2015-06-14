# ugly numbers soln in py2 for code eval by steven a dunn

import sys

count = 0

def count_uglies(n):
  
  pass

f = open(sys.argv[1], 'r')
for line in f:
  count = 0
  n = line.rstrip()
  count_uglies(n)
  print count
f.close()