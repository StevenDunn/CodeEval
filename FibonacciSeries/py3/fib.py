# Fibonacci Series solution written in Python 3 for CodeEval.com by Steven A. Dunn

def fib(n):
  buf1 = 1
  buf2 = 1
  temp = 0

  if n == 0: return 0
  if n == 1 or n == 2: return 1
  for fibIdx in range(3, n + 1):
    temp = buf1
    buf1 = buf2
    buf2 = buf1 + temp

  return buf2

import sys

for line in open(sys.argv[1], 'r'):
  print (fib(int(line)))
