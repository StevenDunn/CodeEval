# closest pair soln in py3 for code eval by steven a dunn

import sys, math

MAX_DISTANCE = 10000
tuples = []

def find_distance(t1, t2):
	return math.sqrt(math.pow((t2[0] - t1[0]), 2) + math.pow((t2[1] - t1[1]), 2))

def find_closest_pair():
	global tuples

	min_distance = MAX_DISTANCE
	for i in range(len(tuples)):
		for j in range(i+1, len(tuples)):
			dist = find_distance(tuples[i], tuples[j])
			if dist < min_distance:
				min_distance = dist
	return min_distance

f = open(sys.argv[1])
first_line = f.readline()
for line in f:
	line = line.strip().split()
	if len(line) == 1:
		result = find_closest_pair()
		if result < MAX_DISTANCE:
			print("%.4f" % result)
		else:
			print ("INFINITY")
		tuples = []
	else:
		x, y = list(map(int, line))
		tuples.append((x, y))	
f.close()