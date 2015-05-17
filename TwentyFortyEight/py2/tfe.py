# 2048 soln in py2 for code eval by steven a dunn

import sys

def parse_line(line):
	line = line.strip().split(";")
	move, n, seq = line[0], int(line[1]), line[2]
	seq = map(int, seq.replace("|", " ").split())
	return move, n, seq

def create_grid(n, seq):
	grid = [[0 for x in range(n)] for x in range(n)]
	seq_idx = 0
	for i in range(n):
		for j in range(n):
			grid[i][j] = seq[seq_idx]
			seq_idx += 1
	return grid

def slide_left(grid, n, i):
	for j in range(1, n):
		k = j
		while k > 0:
			if grid[i][k-1] == 0:
				grid[i][k-1], grid[i][k] = grid[i][k], grid[i][k-1]
			k -= 1
	return grid

def move_left(grid, n):
	for i in range(n):
		grid = slide_left(grid, n, i)
		for j in range(1, n):
			if grid[i][j] == grid[i][j-1]:
				grid[i][j] = 0
				grid[i][j-1] *= 2
		grid = slide_left(grid, n, i)
	return grid

def slide_right(grid, n, i):
	for j in range(n-2, -1, -1):
		k = j
		while k < n-1:
			if grid[i][k+1] == 0:
				grid[i][k], grid[i][k+1] = grid[i][k+1], grid[i][k]
			k += 1
	return grid

def move_right(grid, n):
	for i in range(n):
		grid = slide_right(grid, n, i)
		for j in range(n-2, -1, -1):
			if grid[i][j] == grid[i][j+1]:
				grid[i][j] = 0
				grid[i][j+1] *= 2
		grid = slide_right(grid, n, i)
	return grid

def slide_up(grid, n, j):
	for i in range(1, n):
		k = i
		while k > 0:
			if grid[k-1][j] == 0:
				grid[k][j], grid[k-1][j] = grid[k-1][j], grid[k][j]
			k -= 1
	return grid

def move_up(grid, n):
	for j in range(n):
		grid = slide_up(grid, n, j)
		for i in range(1, n):
			if grid[i][j] == grid[i-1][j]:
				grid[i][j] = 0
				grid[i-1][j] *= 2
		grid = slide_up(grid, n, j)
	return grid

def slide_down(grid, n, j):
	for i in range(n-2, -1, -1):
		k = i
		while k < n-1:
			if grid[k+1][j] == 0:
				grid[k][j], grid[k+1][j] = grid[k+1][j], grid[k][j]
			k += 1
	return grid

def move_down(grid, n):
	for j in range(n):
		grid = slide_down(grid, n, j)
		for i in range(n-2, -1, -1):
			if grid[i][j] == grid[i+1][j]:
				grid[i][j] = 0
				grid[i+1][j] *= 2
		grid = slide_down(grid, n, j)
	return grid

def update_grid(move, grid, n):
	if move == "LEFT":
		grid = move_left(grid, n)
	if move == "RIGHT":
		grid = move_right(grid, n)
	if move == "UP":
		grid = move_up(grid, n)
	if move == "DOWN":
		grid = move_down(grid, n)
	return grid

def print_grid(grid, n):
	line = ""
	for i in range(n):
		for j in range(n):
			line += str(grid[i][j]) + " "
		line = line[0:-1]
		line += "|"
	print line[0:-1]

f = open(sys.argv[1], 'r')
for line in f:
	move, n, seq = parse_line(line)
	grid = create_grid(n, seq)
	updated_grid = update_grid(move, grid, n)
	print_grid(updated_grid,n)
f.close()