# strings and arrows soln in py2 for code eval by steven a dunn
import sys, re

f = open(sys.argv[1], 'r')
for line in f:
  total = 0
  total += len(re.findall('(?=<--<<)', line))
  total += len(re.findall('(?=>>-->)', line))
  print total
f.close()