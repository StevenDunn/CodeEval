#longest common subsequence soln in py2 for code eval by steven a dunn// LCS solution in C++ for CodeEval.com by Steven A. Dunn

import sys

def backtrack(c, x, y, i, j):
	if i == 0 or j == 0:
		return ""
	elif x[i-1] == y[j-1]:
		return backtrack(c, x, y, i-1, j-1) + x[i-1]
	elif c[i][j-1] > c[i-1][j]:
		return backtrack(c, x, y, i, j-1)
	else:
		return backtrack(c, x, y, i-1, j)

def LCS(x, y):
	m, n = len(x), len(y)
	c = [[0 for i in range(n+1)] for j in range(m+1)]
	for i in range(m+1):
		for j in range(n+1):
			if i == 0 or j == 0:
				c[i][j] = 0
			elif x[i-1] == y[j-1]:
				c[i][j] = c[i-1][j-1] + 1
			else:
				c[i][j] = max(c[i-1][j], c[i][j-1])
	return backtrack(c, x, y, m, n)

f = open(sys.argv[1], 'r')
for line in f:
	if not line:
		continue
	x, y = line.strip().split(';')
	print LCS(x, y)
f.close();