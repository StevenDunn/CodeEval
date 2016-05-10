# string list soln in py2 for code eval by steven a dunn

import sys, itertools

f = open(sys.argv[1], 'r')
for line in f:
	n, s = line.strip().split(",")
	n = int(n)
	for i in range(n):
		s += s
	perms = sorted(set(itertools.permutations(s, n)))
	result = []
	i = 0
	while i < len(perms):
		entry = "".join(perms[i])
		result.append(entry)
		i += 1
	print ",".join(result)
f.close()