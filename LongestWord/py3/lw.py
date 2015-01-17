# Longest Word solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  counts = list(map(lambda s: int(len(s)), line))
  longest = line[counts.index(max(counts))]
  print (longest)
