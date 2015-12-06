# lucky tickets soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
  print line
  n = int(line)
  end = int('9' * n)
  for i in range(end+1):
    pass
  print end
f.close()