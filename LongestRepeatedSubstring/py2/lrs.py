# longest repeated substring soln in py2 for code eval by steven a dunn

import sys

def lcp(s1, s2):
	n = min(len(s1), len(s2))
	for i in range(n):
		if s1[i] != s2[i]:
			return s1[0:i]
	if s2[n-1:] == s1:
		return s1[0:n-1]
	return s1[0:n]

def find_lrs(line):
	suffixes = []
	for i in range(len(line)):
		suffixes.append(line[i:])
	suffixes = sorted(suffixes)
	lrs = ""
	for i in range(len(line) - 1):
		prefix = lcp(suffixes[i], suffixes[i+1])
		if len(prefix) > len(lrs):
			lrs = prefix
	return "".join(lrs.split())

f = open(sys.argv[1], 'r')
for line in f:
	print "".join(line.strip().split())
	result = find_lrs(line.strip())
	if not result:
		print "NONE"
	else:
		print result
f.close()