# chardonnay or cabernet soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
	line = line.rstrip().split(' | ')
	wines, text = line[0].split(), line[1].strip()
	
	results = []
	for wine in wines:
		validWine = True
		localWine = wine[:].lower()
		for char in text:
			if char in localWine:
				localWine = localWine.replace(char, "", 1)
			else:
				validWine = False
				break
		if validWine:
			results.append(wine)
		
	if len(results) > 0:
		print ' '.join(results)
	else:
		print "False",
	print
f.close()