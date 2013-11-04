# Remove Characters solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(", ")
  for c in line[1]:
    line[0] = line[0].replace(c, "")
  print line[0]
