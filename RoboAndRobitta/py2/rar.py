# robo and robitta soln in py2 for code eval by steven a dunn

import sys

def parse_line(line):
  line = line.strip().split(' | ')
  dims, end = line[0].strip(), line[1].strip()
  dims = list(map(int, dims.split('x')))
  M, N = dims[0], dims[1]
  end = list(map(int, end.split()))
  end[0] -= 1
  end[1] -= 1
  #end[0], end[1] = end[1], end[0]
  return M, N, end

def is_end(i, j, end):
  if i == end[0] and j == end[1]:
    return True
  return False

def walk_path(M, N, end):
  i = 0
  j = 0
  steps = 0
  while True:
    if M <= 0 or N <= 0:
      return
    for idx in range(M):
      #print i, j, end
      if is_end(i, j, end):
        return steps
      i += 1
      steps += 1
    i -= 1
    for idx in range(N-1):
      #print i, j
      if is_end(i, j, end):
        return steps
      j += 1
      steps += 1
    for idx in range(M-1):
      #print i, j
      if is_end(i, j, end):
        return steps
      i -= 1
      steps += 1
    for idx in range(N-2):
      #print i, j
      if is_end(i, j, end):
        return steps
      j -= 1
      steps += 1
    if is_end(i, j, end):
      return steps
    i += 1
    N -= 2
    M -= 2
  return 0

f = open(sys.argv[1], 'r')
for line in f:
  #print line
  M, N, end = parse_line(line)
  steps = walk_path(M, N, end)
  #print steps
  print steps - 1
f.close()