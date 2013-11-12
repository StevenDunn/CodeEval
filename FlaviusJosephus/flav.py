# Flavius Josephus solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(',')
  N = int(line[0])
  M = int(line[1])

  visited = [0] * N
  elements_visited = 0
  results = []
  step_count = 0

  i = -1
  while i < N+1:
    i += 1

    if i is N:
      i = -1
      continue

    if visited[i] is 1:
      continue

    if not step_count is M - 1:
      step_count += 1
      continue

    if visited[i] is 0:
      visited[i] = 1
      elements_visited += 1
      results.append(i)
      if elements_visited == N:
        break
      step_count = 0
      continue

  for i in results:
    print i,
  print
