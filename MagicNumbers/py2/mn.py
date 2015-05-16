# magic numbers soln in py2 for code eval by steven a dunn

import sys

def isMagic(x):
	number_str = str(x)
	for i in range (0, 10):
		counts = number_str.count(str(i))
		if counts > 1:
			return False

	visited_digits = [False] * len(number_str)

	cur = 0
	while True:
		cur += int(number_str[cur])
		cur %= len(number_str)
		if visited_digits[cur] == True:
			return False
		visited_digits[cur] = True
		if cur == 0:
			for val in visited_digits:
				if val == False:
					return False
			return True


f = open(sys.argv[1], 'r')

for line in f:
	magic_found = False
	a, b = map(int, line.strip().split(" "))
	for x in range(a, b+1):
		if isMagic(x):
			magic_found = True
			print x,
	if not magic_found:
		print -1,
	print
f.close()