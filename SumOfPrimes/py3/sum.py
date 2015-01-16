# Sum of Primes solution in Python 3 for CodeEval.com by Steven A. Dunn

def isPrime(n):
  if n % 2 == 0: return False
  for i in range(3, n, 2):
    if n % i == 0: return False
  return True

primeSum = 2
num = 3
primeCount = 1
while primeCount < 1000:
  if isPrime(num):
    primeSum += num
    primeCount += 1
  num = num + 2
print (primeSum)
