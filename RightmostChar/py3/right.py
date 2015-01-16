# Rightmost Char solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  if not line: continue
  params = line.rstrip('\n').split(',')
  print (params[0].rfind(params[1]))
