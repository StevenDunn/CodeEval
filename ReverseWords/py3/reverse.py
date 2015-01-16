# Reverse Words solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

f = open(sys.argv[1], 'r');

for line in f:
  words = line.split()
  words.reverse()
  for word in words:
    print (word, end=" ")
  print()
