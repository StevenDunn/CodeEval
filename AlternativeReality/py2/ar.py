# alternative reality soln in py2 for code eval by steven a dunn
# this soln is adapted from https://andrew.neitsch.ca/publications/m496pres1.nb.pdf

import sys

coins = [1, 5, 10, 25, 50]

def count_change(n, k):
  global coins

  if k < 0 or n < 0:
    return 0
  if n == 0:
    return 1
  return count_change(n, k-1) + count_change(n-coins[k], k)
  

f = open(sys.argv[1], 'r')
for line in f:
  print count_change(int(line), len(coins)-1)
f.close()