# Shortest Repetition solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n')
  period = 1
  subSeq = line[0]
  for i in range(1, len(line)):
    if not line[period:].find(subSeq) == 0:
      period += 1
      subSeq += line[i]

  print(period)