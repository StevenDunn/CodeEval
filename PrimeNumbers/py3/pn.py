# Prime Numbers solution in Python 3 for CodeEval.com by Steven A. Dunn

def isPrime(N):
  for i in range(2, N//2 + 1):
    if N % i == 0: return False
  return True

import sys

for line in open(sys.argv[1], 'r'):
  N = int(line)
  primes = [2]
  i = 3
  while i < N:
    if isPrime(i):
      primes.append(i)
    i += 1

  for i in range(0, len(primes) - 1):
    sys.stdout.write(str(primes[i]) + ",")
  print (primes[-1])
