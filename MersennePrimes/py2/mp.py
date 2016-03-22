# mersenne primes soln in py2 for code eval by steven a dunn

import sys

def is_prime(n):
  for i in range(2, n/2 + 1):
    if n % i == 0: return False
  return True

f = open(sys.argv[1], 'r')
for line in f:
	lim = int(line)
	p = 2
	num = (2 ** p) - 1
	results = []
	while num <= lim:
		if is_prime(p):
			results.append(num)
		p += 1
		num = (2 ** p) - 1
	print ", ".join(map(str, results))
f.close();