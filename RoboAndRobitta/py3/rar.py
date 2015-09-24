# robo and robitta soln for code eval by steven a dunn

import sys

end_x = 0
end_y = 0
steps = 0

def is_end(i, j):
	global end_x, end_y, steps
	if i == end_x and j == end_y:
		print(steps)
		return True
	return False

def walk_path(M, N):
	global steps
	i = 0
	j = 0
	while True:
		if M <= 0 or N <= 0:
			return
		for idx in range(M):
			i += 1
			steps += 1
			if is_end(i, j):
				return
		for idx in range(N-1):
			j += M
			if is_end(i, j):
				return
		for idx in range(M-1):
			i -= 1
			if is_end(i, j):
				return
		for idx in range(N-2):
			j -= M
			if is_end(i, j):
				return
		N -= 2
		M -= 2

f = open(sys.argv[1], 'r')
for line in f:
	line = line.strip().split(' | ')
	dims, end = line[0].strip(), line[1].strip()
	dims = list(map(int, dims.split('x')))
	M, N = dims[0], dims[1]
	end = list(map(int, end.split()))
	end_x, end_y = end[0], end[1]
	
	walk_path(M, N)
f.close()