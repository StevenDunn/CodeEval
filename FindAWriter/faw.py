# Find a Writer solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n')

  if not line: continue
  
  line = line.split('|')
  name = line[0]
  key = map(int, line[1].lstrip(' ').split(' '))
 
  for k in key:
    sys.stdout.write(name[k - 1])
  print
