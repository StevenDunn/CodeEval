# trick or treat soln in py3 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
  line = line.strip().split(",")
  vals = []
  for entry in line:
    vals.append(int(entry.split(": ")[1]))
  print ( int( (((3 * vals[0]) + (4 * vals[1]) + (5 * vals[2])) * vals[3])/(vals[0] + vals[1] + vals[2]) ) ) 

f.close()