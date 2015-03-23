# Double Squares solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys, math

cachedVals = [0] * 32767

f = open(sys.argv[1], 'r')
f.readline()

for line in f:
  N = int(line)
  count = 0
  upperLimit = math.sqrt(N/2)
  for i in range(0, int(upperLimit + 1)):
    if cachedVals[i] == 0: cachedVals[i] = i*i
    j = math.sqrt(N - cachedVals[i])
    if j - int(j) == 0.0: count += 1
  print (count)
