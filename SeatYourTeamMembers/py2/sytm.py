# seat your team members soln in py2 for code eval by steven a dunn

import sys

def parse(line):
	line = line.strip().split(";")
	n = int(line[0])

	matches = {}
	line = line[1].split("],")
	for entry in line:
		entry = entry.split(":")
		person = int(entry[0])

		prefs = map(int, entry[1].replace("[", "").replace("]", "").split(","))
		matches[person] = prefs		

	return n, matches


f = open(sys.argv[1], 'r')
for line in f:
	n, matches = parse(line)

	# None == free
	#people = [None] * n
	#desks = [None] * n

	

	print n, matches
	
f.close()