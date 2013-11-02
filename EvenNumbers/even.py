# Even Numbers solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  if int(line) % 2 == 0: print 1
  else: print 0
