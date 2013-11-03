# Detecting Cycles solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  for i in range(0, len(line)):
    idx = [line[0] in line[1:]]
    if idx[0]:
      idx = line[1:].index(line[0]) + 1
      seq = line[0:idx]
      for j in range(0, len(seq) - 1):
        sys.stdout.write(seq[j] + " ")
      sys.stdout.write(seq[-1] + "\n")
      break
    else:
      line = line[1:]
