# commuting engineer soln in py2 for code eval by steven a dunn

import math, sys

# modified from this gist: https://gist.github.com/siddMahen/8261350
def prim_mst(matrix):
	T = set()
	X = set()

	X.add(0)

	num_vertices = int(math.sqrt(len(matrix)))
	while len(X) != num_vertices:
		crossing = set()
		# add (x, k) to crossing if k is not in X
		for x in X:
			for k in range(num_vertices):
				if k not in X and matrix[x, k] != 0:
					crossing.add((x, k))
		# find edge with smallest weight in crossing
		edge = sorted(crossing, key=lambda e:matrix[e[0], e[1]])[0]
		T.add(edge)
		X.add(edge[1])

	return T

def create_distance_matrix(locations):
	matrix = {}
	
	for i, (x1, y1) in enumerate(locations):
		for j, (x2, y2) in enumerate(locations):
			dx2 = (x1 - x2) * (x1 - x2)
			dy2 = (y1 - y2) * (y1 - y2)
			matrix[i, j] = math.sqrt(dx2 + dy2)
	return matrix

# parse the file & generate the initial data structure
locations = []
f = open(sys.argv[1], 'r')
for line in f:
	print line

	line = line.strip().split("|")
	index = int(line[0])

	coord_str = line[1][line[1].find("("):]
	coords = coord_str[1:-1].split(",")
	coords = map(float, coords)

	locations.append((coords[0], coords[1]))
f.close()

print

# store distances in a matrix
matrix = create_distance_matrix(locations)

print matrix

print

mst = prim_mst(matrix)

print mst