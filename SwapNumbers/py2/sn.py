# swap numbers soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
	words = line.rstrip().split(" ")
	for i in range(0, len(words)):
		word = words[i]
		words[i] = word[-1] + word[1:-1] + word[0]
	print " ".join(words)
f.close()