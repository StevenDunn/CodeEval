# robo and robitta soln in py2 for code eval by steven a dunn

import sys

def parse_line(line):
  dims, end = line.strip().split(' | ')
  M, N = list(map(int, dims.split('x')))
  end = list(map(int, end.split()))
  end = [x - 1 for x in end]
  end[0], end[1] = end[1], end[0]
  return M, N, end

def is_end(i, j, end):
  if i == end[0] and j == end[1]:
    return True
  return False

def walk_path(M, N, end):
  i = 0
  j = 0
  nuts = 0
  while True:
    if M <= 0 or N <= 0:
      return

    #walk right
    for idx in range(N):
      nuts += 1
      if is_end(i, j, end):
        return nuts
      i += 1
      
    #walk down
    i -= 1
    j += 1
    for idx in range(M-1):
      nuts += 1
      if is_end(i, j, end):
        return nuts
      j += 1

    #walk left
    j -= 1
    i -= 1
    for idx in range(N-1):
      nuts += 1
      if is_end(i, j, end):
        return nuts
      i -= 1

    #walk up
    i += 1
    j -= 1
    for idx in range(M-2):
      nuts += 1
      if is_end(i, j, end):
        return nuts
      j -= 1

    i += 1
    j += 1

    N -= 2
    M -= 2

  return 0

f = open(sys.argv[1], 'r')
for line in f:
  M, N, end = parse_line(line)
  steps = walk_path(M, N, end)
  print steps - 1
f.close()