# time to eat solution in py2 for code eval by steven a dunn

import sys, datetime

f = open(sys.argv[1], 'r')
for line in f:
	timestamps = sorted(line.strip().split(), reverse=True)
	print ' '.join(timestamps)
f.close()