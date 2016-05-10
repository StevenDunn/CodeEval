# climbing stairs soln in py2 for code eval by steven a dunn

import sys

def fib(n):
	buf1, buf2, temp = 1, 1, 0
	if n == 1 or n == 2: 
		return 1
	else:
		for i in range(3, n+1):
			temp = buf1
			buf1 = buf2
			buf2 = buf1 + temp
	return buf2

def get_num_climbs(num_stairs):
	return fib(num_stairs + 1)

f = open(sys.argv[1], 'r')
for line in f:
	print get_num_climbs(int(line))
f.close()