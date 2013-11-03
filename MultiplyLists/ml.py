# Multiply Lists solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(" | ")
  line = [i.split(' ') for i in line] 
  line = [map(int, i) for i in line] 

  result = map(lambda x,y: x * y, line[0], line[1])
  
  for n in result:
    print n,
  print
