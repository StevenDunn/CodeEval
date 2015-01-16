# Lowest Unique Number solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  nums = line.strip('\n').split(' ')
  lowest = 10
  for i in nums:
    if nums.count(i) == 1 and int(i) < lowest:
      lowest = int(i)
  if lowest == 10: print 0
  else: print nums.index(str(lowest)) + 1
