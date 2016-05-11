# minimum path sum soln for code eval by steven a dunn

import sys

matrix = []

def init_matrix(n):
	global matrix
	matrix = [[]] * n
	for i in range(n):
		matrix[i] = [0] * n

def find_min_sum():
	global matrix
	min_sum = matrix[0][0]
	sums = []
	sums.append([min_sum, (0, 0)])
	while sums:
		smallest_idx = 0
		smallest, smallest_idx = get_smallest(sums, smallest_idx)
		if is_end(smallest, len(matrix)):
			return smallest[0]
		adjx = get_adjacent_x(smallest)
		adjy = get_adjacent_y(smallest)
		if adjx:
			sums.append(adjx)
		if adjy:
			sums.append(adjy)
		del sums[smallest_idx]
	return min_sum

def get_smallest(sums, smallest_idx):
	smallest_sum = sums[0][0]
	smallest = sums[0];
	for i in range(1, len(sums)):
		if sums[i][0] < smallest_sum:
			smallest_sum = sums[i][0]
			smallest_idx = i
			smallest = sums[i]
	return smallest, smallest_idx

def is_end(node, n):
	indices = node[1]
	if indices[0] == n-1 and indices[1] == n-1:
		return True 
	return False 

def get_adjacent_x(root):
	global matrix
	x = root[1][0]
	y = root[1][1]
	if x+1 == len(matrix):
		return None
	adj = [root[0]+matrix[x+1][y], (x+1, y)]
	return adj

def get_adjacent_y(root):
	global matrix
	x = root[1][0]
	y = root[1][1]
	if y+1 == len(matrix):
		return None
	adj = [root[0]+matrix[x][y+1], (x, y+1)]
	return adj

row_idx = 0
f = open(sys.argv[1], 'r')
for line in f:
	if not "," in line:
		if matrix:
			print (find_min_sum())
		init_matrix(int(line))
		row_idx = 0
	else:
		row = list(map(int, line.split(",")))
		for i in range(len(row)):
			matrix[i][row_idx] = row[i]
		row_idx += 1
print (find_min_sum())
f.close()