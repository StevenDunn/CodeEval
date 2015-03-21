# Mth to Last Element solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  idx = int(line[-1])
  line = line[0:-1]
  try: print line[-idx]
  except IndexError: continue
