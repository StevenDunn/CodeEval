# First Non-Repeated Character solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n')
  for c in line:
    if line.count(c) == 1:
      print c
      break
