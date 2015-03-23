# Reverse Groups solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys, itertools

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(';')
  k = int(line[1])
  numbers = line[0].split(',')
  result = []
  for i in range(0,len(numbers),k):
    sub = numbers[i:i+k]
    if len(sub) == k:
      result.append(sub[::-1])
    else: result.append(sub)
  # flatten list for easier printing
  result = list(itertools.chain.from_iterable(result))
  for i in range(0, len(result)-1):
    sys.stdout.write(str(result[i]) + ",")
  print result[-1]
