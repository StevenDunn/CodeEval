# Counting Primes solution in Python 2 for CodeEval.com by Steven A. Dunn

def isPrime(N):
  for i in range(2, (N//2)+1):
    if N % i == 0: return False
  return True

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(',')
  N, M, primeCount = int(line[0]), int(line[1]), 0
  for i in range(N, M+1):
    if isPrime(i): primeCount += 1
  print (primeCount)
