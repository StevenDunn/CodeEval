# Set Intersection solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  params = line.rstrip('\n').split(';')

  set1 = set(params[0].split(','))
  set2 = set(params[1].split(','))

  intersection = set1.intersection(set2)

  intersection = list(map(int, list(intersection)))
  intersection.sort()

  if len(intersection) == 0:
    print()
  elif len(intersection) == 1:
    print(intersection[0])
  else:
    for i in range(0, len(intersection) - 1):
      sys.stdout.write("%d," % intersection[i])

    print(intersection[-1])
