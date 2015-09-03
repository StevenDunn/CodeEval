# find the highest score solution in py2 for code eval by steven a dunn

import sys
from operator import itemgetter

f = open(sys.argv[1], 'r')
for line in f:
	scores = []
	line = line.split(" | ")
	for i in range(len(line)):
		scores.append(list(map(int, line[i].split())))
	scores = list(zip(*scores))
	print " ".join([str(max(i)) for i in scores])
f.close()
