# lucky tickets soln in py2 for code eval by steven a dunn

import sys


f = open(sys.argv[1], 'r')
for line in f:
  n = int(line)
  max_sum = 9 * (n/2)
  count = 0

  for i in range(1, 10):
    count += i * (i + 1)

  for i in range(10, max_sum+1):
    count += (max_sum+1 - i)**2

  count += 55

  print count

"""
  for i in range(1, 10**(n/2 - 1)):
    print i
    count += i * i

  count *= 2
  count += 10**(n/2)
"""
 # print count
f.close()