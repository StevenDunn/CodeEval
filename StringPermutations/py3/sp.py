# String Permutations solution in py3 for CodeEval.com

import sys

permutations = []

def find_permutations(line, idx):
  global permutations
  if idx == len(line):
    permutations.append(line[:])
    return

  for i in range(idx, len(line), 1):
    line[idx], line[i] = line[i], line[idx]
    find_permutations(line, idx + 1)
    line[idx], line[i] = line[i], line[idx]

f = open(sys.argv[1], 'r')
for line in f:
  line = list(line.strip())
  find_permutations(line, 0)
  permutations.sort()
  for idx, p in enumerate(permutations):
    permutations[idx] = "".join(p)
  print (",".join(permutations))
  permutations = []
f.close()

