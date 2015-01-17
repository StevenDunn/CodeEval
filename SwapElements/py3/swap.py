# Swap Elements solution in Python 3 by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(" : ")
  numbers = line[0].split(' ')
  swaps = line[1].split(", ")

  for swap in swaps:
    swap = swap.split('-')
    tmp = numbers[int(swap[0])]
    numbers[int(swap[0])] = numbers[int(swap[1])]
    numbers[int(swap[1])] = tmp

  for i in numbers:
    sys.stdout.write(i + " ")
  print()
