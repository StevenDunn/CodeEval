# word search soln in py3 for code eval by steven a dunn

import sys

grid = []
visited = []

class Directions:
	UP, DOWN, LEFT, RIGHT = range(4)

def setup_grid():
	global grid
	global visited

	grid = [
		['A', 'S', 'A'], 
		['B', 'F', 'D'], 
		['C', 'C', 'E'], 
		['E', 'S', 'E']
		]
	visited = [
		[False, False, False], 
		[False, False, False], 
		[False, False, False], 
		[False, False, False]
		]

def clear_grid():
	global visited
	for i in range(4):
		for j in range(3):
			visited[i][j] = False

def does_word_exist(line):
	global grid
	global visited
	init_char = line[0]
	result = False
	for i in range(4):
		for j in range(3):
			if grid[i][j] == init_char:
				result = search(i, j, line)
				if result:
					return "True"
			visited[i][j] = False
	return "False"

def search(i, j, line):
	global visited
	visited[i][j] = True
	line = line[1:]
	if not line:
		return True

	original_i = i
	original_j = j
	continuations = find_continuations(i, j, line)
	if continuations:
		for k in range(len(continuations)):
			i, j = update_indices(i, j, continuations[k])
			if search(i, j, line):
				return True
			visited[i][j] = False
			i = original_i
			j = original_j
		return False
	else:
		return False

def find_continuations(i, j, line):
	continuations = []
	next_letter = line[0]

	if upper_matches(i, j, next_letter):
		continuations.append(Directions.UP)
	if lower_matches(i, j, next_letter):
		continuations.append(Directions.DOWN)
	if left_matches(i, j, next_letter):
		continuations.append(Directions.LEFT)
	if right_matches(i, j, next_letter):
		continuations.append(Directions.RIGHT)
	return continuations

def upper_matches(i, j, letter):
	global grid
	global visited
	if j > 0 and grid[i][j-1] == letter and visited[i][j-1] == False:
		return True
	return False

def lower_matches(i, j, letter):
	global grid
	global visited
	if j < 2 and grid[i][j+1] == letter and visited[i][j+1] == False:
		return True
	return False

def left_matches(i, j, letter):
	global grid
	global visited
	if i > 0 and grid[i-1][j] == letter and visited[i-1][j] == False:
		return True
	return False

def right_matches(i, j, letter):
	global grid
	global visited
	if i < 3 and grid[i+1][j] == letter and visited[i+1][j] == False:
		return True
	return False

def update_indices(i, j, continuation):
	if continuation == Directions.UP:
		j -= 1
	elif continuation == Directions.DOWN:
		j += 1
	elif continuation == Directions.LEFT:
		i -= 1
	elif continuation == Directions.RIGHT:
		i += 1
	return [i, j]

setup_grid()
f = open(sys.argv[1], 'r')
for line in f:
	clear_grid()
	print (does_word_exist(line.strip()))
f.close()