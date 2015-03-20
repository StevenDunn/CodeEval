# Longest Lines solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

f = open(sys.argv[1], 'r')
N = int(f.readline())

lines = []
for line in f:
  lines.append(line.rstrip('\n'))
lines.sort(key=len, reverse=True)

for i in range(0, N):
  print (lines[i])
