# brainfuck soln for code eval by steven a dunn

import sys

def find_end(line, start):
	count = 1
	for i in range(start+1, len(line)):
		if line[i] == "[":
			count += 1
		elif line[i] == "]":
			count -= 1
			if count == 0:
				return i
	return len(line) -1

def find_start(line, end):
	count = 1
	for i in range(end-1, -1, -1):
		if line[i] == "]":
			count += 1
		elif line[i] == "[":
			count -= 1
			if count == 0:
				return i
	return 0 

f = open(sys.argv[1], 'r')
for line in f:
	line = list(line.strip())
	cells, ptr, idx = [0], 0, 0
	result = []
	while idx < len(line):
		cur = line[idx]
		if cur == ".":
			result.append(chr(cells[ptr]))
		elif cur == "+":
			cells[ptr] += 1
			cells[ptr] %= 255
		elif cur == "-":
			cells[ptr] -= 1
			cells[ptr] %= 255
		elif cur == ">":
			ptr += 1
			if ptr >= len(cells):
				cells.append(0)
		elif cur == "<":
			ptr -= 1
			if ptr < 0:
				cells = [0] + cells
				ptr = 0
		elif cur == "[":
			if cells[ptr] == 0:
				idx = find_end(line, idx)
		elif cur == "]":
			if cells[ptr] != 0:
				idx = find_start(line, idx)
		idx += 1
	print "".join(result)
f.close()