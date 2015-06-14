# sort matrix columns soln in py2 for code eval by steven a dunn

import sys
from operator import itemgetter

f = open(sys.argv[1], 'r')
for line in f:
  n = line.split().index("|")
  vals = map(int, filter(lambda x: x != "|", line.rstrip().split()))

  cols = []
  for offset in range(n):
    col = []
    for i in range(offset, len(vals), n):
      col.append(vals[i])
    cols.append(col)
  
  indices = (0,)
  indices = list(indices)
  for i in range(1, n):
    indices.append(i)
  indices = tuple(indices)

  cols = sorted(cols, key=itemgetter(*(indices)))
  vals = [item for sublist in cols for item in sublist]

  result = ""
  for offset in range(n-1):
    col = ""
    for i in range(offset, len(vals) - 1, n):
      print vals[i],
    print "|",
  for i in range(n-1, len(vals), n):
    print vals[i],
  print
f.close()