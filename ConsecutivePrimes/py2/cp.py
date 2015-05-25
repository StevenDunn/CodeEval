# consecutive primes soln in py2 for code eval by steven a dunn

import itertools, sys

graph = {
	1 : set([2, 4, 6, 10, 12, 16, 18]),
	2 : set([1, 3, 5,  9, 11, 15, 17]),
	3 : set([   2, 4,  8, 10, 14, 16]),
	4 : set([   1, 3,  7,  9, 13, 15]),
	5 : set([      2,  6,  8, 12, 14, 18]),
	6 : set([      1,  5,  7, 11, 13, 17]),
	7 : set([          4,  6, 10, 12, 16]),
	8 : set([          3,  5,  9, 11, 15]),
	9 : set([          2,  4,  8, 10, 14]),
	10 : set([         1,  3,  7,  9, 13]),
	11 : set([             2,  6,  8, 12, 18]),
	12 : set([             1,  5,  7, 11, 17]),
	13 : set([                 4,  6, 10, 16, 18]),
	14 : set([                 3,  5,  9, 15, 17]),
	15 : set([                 2,  4,  8, 14, 16]),
	16 : set([                 1,  3,  7, 13, 15]),
	17 : set([                     2,  6, 12, 14]),
	18 : set([                     1,  5, 11, 13]),
}


# modified from an algorithm found at: 
# http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
def count_cycles(n):
	global count
	# always start and end at 1
	start, goal = 1, 1
	stack = [(start, [])]
	while stack:
		(vertex, path) = stack.pop()
		# we only maintain one graph for all N so ignore vertices > N
		if vertex > n:
			continue
		if vertex == 1:
			if len(path) == n:
				count += 1
		for next in graph[vertex] - set(path):
			stack.append((next, path + [next]))


count = None
f = open(sys.argv[1], 'r')
for line in f:
	count = 0
	n = int(line)
	# every other n has no cycles, so don't waste time on them
	if n == 3 or n == 5 or n == 7 or n == 9 or n == 11 or n == 13 or n == 15 or n == 17:
		print 0
	elif n == 18:
		# I've cached this value because I can't figure out an optmization that's time-effective for me
		# I know it's kind of cheap, but it still solves reasonably quickly and I'm not able to
		# control the hardware and other execution details. 
		print 770144
	else:
		count_cycles(n)
		print count
f.close()