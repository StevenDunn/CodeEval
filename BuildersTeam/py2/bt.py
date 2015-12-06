# builders team soln in py2 for code eval by steven a dunn

import sys

graph = {}

def parse_edges(line):
  line = line.strip().split(" | ")
  line = [map(int, entry.split()) for entry in line]
  return line

def create_graph(edges):
  graph = {}
  for i in range(1, 26):
    graph[i] = []

  for edge in edges:
    graph[edge[0]].append(edge[1])
    graph[edge[1]].append(edge[0])

  return graph

def has_edge(start, end):
  if end in graph[start]:
    return True
  return False

def square_exists(start, size):
  # no squares exist when starting in final column
  if start % 5 == 0:
    return False

  # left to right
  for i in range(0, size):
    if not has_edge(start + i, start + i + 1):
      return False

  # top to bottom
  for i in range(0, size):
    if not has_edge(start + size + (5 * i), start + size + (5 * (i + 1))):
      return False

  # right to left
  for i in range(0, size):
    if not has_edge(start + size + (5 * size) - i, start + size + (5 * size) - (i + 1)):
      return False

  # bottom to top
  for i in range(0, size):
    if not has_edge(start + (5 * size) - (5 * i), start + (5 * size) - 5 * (i + 1)):
      return False

  return True

def count_squares():
  count = 0
  # no need to start in the final row
  for start in range(1, 20):
    for size in range(1, 5):
      if square_exists(start, size):
        count += 1
  return count

f = open(sys.argv[1], 'r')
for line in f:
  graph = create_graph(parse_edges(line))
  print count_squares()
f.close()