# Sum to Zero solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

count = 0

def count_sums(numbers, depth, sum):
  global count
  if depth == 0:
    if sum == 0:
      count += 1
    return

  updated_sum = 0
  for i in range(0, len(numbers)):
    num = numbers[i]
    updated_sum = sum + num
    del numbers[i]
    count_sums(numbers, depth - 1, updated_sum)
    numbers.insert(i, num)

for line in open(sys.argv[1], 'r'):
  numbers = map(int, line.rstrip('\n').split(','))

  count = 0
  count_sums(numbers, 4, 0)
  print count/24
