# testing soln in py2 for code eval by steven a dunn

import sys

def print_error(count):
  if count == 0:
    print "Done"
  elif count <= 2:
    print "Low"
  elif count <= 4:
    print "Medium"
  elif count <= 6:
    print "High"
  else:
    print "Critical"

f = open(sys.argv[1], 'r')
for line in f:
  line = line.strip().split(" | ")
  text, ref = line[0], line[1]
  count = 0

  for i in range(len(text)):
    c1, c2 = text[i], ref[i]
    if c1 != c2:
      count += 1
  print_error(count)
f.close()