# spiral printing soln in py2 for code eval by steven a dunn

import sys

def spiral_print(n, m, vals):
	cur = 0
	size = n * m
	n_step = m
	visited = 0
	while True:
		for i in range(m):
			print vals[cur],
			cur += 1
			visited += 1
		if visited == size:
			break
		cur -= 1

		for j in range(n-1):
			cur += n_step
			visited += 1
			print vals[cur],
		if visited == size:
			break

		for i in range(m-1):
			cur -= 1
			visited += 1
			print vals[cur], 
		if visited == size:
			break

		for j in range(n-2):
			cur -= n_step
			visited += 1
			print vals[cur],
		if visited == size:
			break
		cur += 1
		n -= 2
		m -= 2
	print

f = open(sys.argv[1], 'r')
for line in f:
	line = line.strip().split(";")
	n, m = int(line[0]), int(line[1])
	vals = line[2].split()
	spiral_print(n, m, vals)
f.close()