# compare points soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
	o, p, q, r = map(int, line.strip().split(" "))
	
	if o == q:
		if p == r: print "here"
		if p < r: print "N"
		if p > r: print "S"
	if o < q:
		if p == r: print "E"
		if p < r: print "NE"
		if p > r: print "SE"
	if o > q:
		if p == r: print "W"
		if p < r: print "NW"
		if p > r: print "SW"
f.close()