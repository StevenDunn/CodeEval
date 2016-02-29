# beat or bit soln in py2 for code eval by steven a dunn


import sys

def convert(num):
	mask = num >> 1
	while mask != 0:
		num = num ^ mask
		mask = mask >> 1
	return str(num)

f = open(sys.argv[1], 'r')
for line in f:
	line = line.strip().split(" | ")
	line = [convert(int(x, 2)) for x in line]
	print " | ".join(line)
f.close()