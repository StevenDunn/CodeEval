# Compressed Sequence solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.strip('\n').split(' ');

  count = 0
  char = line[0]
  for i in line:
    if i == char:
      count += 1
    else:
      print (count, end=" ")
      print (char, end=" ")
      count = 1
      char = i
  print (count, end=" ")
  print (char, end=" ")
  print()
