# data recovery solution in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
  line = line.rstrip().split(";")
  text, order = line[0].split(), line[1].split()
  mapping = zip(order, text)
  print mapping
  mapping.sort()
  for entry in mapping:
    print entry[1],
  print
f.close()