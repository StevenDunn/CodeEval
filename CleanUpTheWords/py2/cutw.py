# clean up the words soln in py2 for code eval by steven a dunn

import sys, re

f = open(sys.argv[1], 'r')
for line in f:
	words = re.compile('[A-Za-z]+').findall(line)
	for word in words:
		print word.lower(),
	print
f.close()