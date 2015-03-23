# Number Pairs solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(';')
  numbers = list(map(int, line[0].split(',')))
  N = int(line[1])

  pairs = []
  for i in range(0, len(numbers)):
    for j in range(i + 1, len(numbers)):
      if numbers[i] + numbers[j] == N: pairs.append((numbers[i], numbers[j]))

  if len(pairs) == 0:
    print ("NULL")
    continue

  for i in range(0, len(pairs) - 1):
    sys.stdout.write(str(pairs[i][0]) + "," + str(pairs[i][1]) + ";")
  sys.stdout.write(str(pairs[-1][0]) + "," + str(pairs[-1][1]) + "\n")
