# find a square soln for code eval by steven a dunn

import sys, math

def parse_coords(line):
	coords = []
	line = line.strip().split(", ")
	for entry in line:
		entry = map(int, entry.strip("(").strip(")").split(","))
		coords.append((entry[0], entry[1]))
	return coords

def is_square(coords):
	distances = []
	if len(set(coords)) < 4:
		return False
	
	for i in range(len(coords)):
		for j in range(i+1, len(coords)):
			distances.append(distance(coords[i], coords[j]))
	distances.sort()
	if distances[0] == distances[1] and distances[1] == distances[2] and distances[2] == distances[3] and distances[4] == distances[5]:
		return True; 
	return False; 

def distance(p1, p2):
	x2 = (p2[0] - p1[0]) * (p2[0] - p1[0]);
  	y2 = (p2[1] - p1[1]) * (p2[1] - p1[1]);
  	return int(math.sqrt(x2 + y2));

f = open(sys.argv[1], 'r')
for line in f:
	print line.strip()
	coords = parse_coords(line)
	if is_square(coords):
		print "true"
	else:
		print "false"
f.close()
