# JSON Ids solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  ids = line.rstrip('\n').split("id")
  ids = filter(None, ids)

  if not ids: continue

  sum = 0

  for i in ids:
    labels = i.split("label")

    for j in labels:
      start = j.find("Label") + 6
      j = j[start:]
      end = j.find("\"")
      j = j[:end]
      try:
        j = int(j)
        sum += j
      except ValueError:
        continue
  print(sum)
