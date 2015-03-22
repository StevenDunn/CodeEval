# Number of Ones solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  print (bin(int(line)).count('1'))
