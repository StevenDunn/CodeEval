# String Rotation solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.strip('\n').split(',')
  doubled_line = line[0] + line[0]
  if not doubled_line.find(line[1]) is -1: print True
  else: print False
