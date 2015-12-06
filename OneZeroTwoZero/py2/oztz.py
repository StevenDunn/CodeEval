# one zero two zero soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
  num_zeros, max_num = map(int, line.strip().split())
  num_count = 0
  for i in xrange(1, max_num + 1):
    binary = str(bin(i))
    zeros = binary.count('0') - 1
    if zeros == num_zeros:
      num_count += 1
  print num_count
f.close()