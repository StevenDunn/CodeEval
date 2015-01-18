# The Major Element solution in Python 3 by Steven A. Dunn for CodeEval.com

import sys

for line in open(sys.argv[1], 'r'):
  entries = list(map(int, line.rstrip('\n').split(',')))
  L = len(entries)
  counts = {}

  for entry in entries:
    if entry in counts:
      counts[entry] = counts[entry] + 1
    else:
      counts[entry] = 1

  result = -1
  for key in counts:
    if counts[key] > L/2:
      result = key
      break

  if result != -1:
    print (result)
  else:
    print ("None")
