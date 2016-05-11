# minsweeper soln for code eval by steven a dunn

import sys

board = []

def find_mines(n):
	global board
	mines = []
	for i in range(len(board)):
		mine_count = num_mines(i, n)
		if mine_count == -1:
			mines.append("*")
		else:
			mines.append(mine_count)
	return mines

def num_mines(i, n):
	global board
	mine_count = 0
	if board[i] == 1:
		return -1
	else:
		xleft = i % n != 0
		xright = (i+1) % n != 0
		ytop = i >= n
		ybottom = i + n <= len(board) - 1
		if xleft and board[i-1] == 1:
			mine_count += 1
		if xright and board[i+1] == 1:
			mine_count += 1
		if ytop and board[i-n] == 1:
			mine_count += 1
		if ybottom and board[i+n] == 1:
			mine_count += 1
		if xleft and ytop and board[i-1-n] == 1:
			mine_count += 1
		if xleft and ybottom and board[i-1+n] == 1:
			mine_count += 1
		if xright and ytop and board[i+1-n] == 1:
			mine_count += 1
		if xright and ybottom and board[i+1+n] == 1:
			mine_count += 1
	return mine_count

f = open(sys.argv[1], 'r')
for line in f:
	line = line.strip().split(";")
	m, n = list(map(int, line[0].split(",")))
	vals = line[1]

	# set up board
	board = [0] * (m * n)
	for i in range(len(board)):
		if vals[i] == '*':
			board[i] = 1
		else:
			board[i] = 0

	mines = find_mines(n)
	print ("".join(map(str, mines)))
f.close()