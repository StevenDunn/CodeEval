# the cubes soln in py2 for code eval by steven a dunn

import sys

MAX_NUM = 999999
INFINITY = MAX_NUM

class Node:
  def __init__(self, coords=[-1,-1], distance=0):
    self.coords = coords
    self.distance = distance

class GraphNode:
  def __init__(self, coords=[-1, -1], distance=0, visited=False, parent=None):
    self.coords = coords
    self.distance = distance
    self.visited = visited
    self.parent = parent

def parse_line(line):
  line = line.strip().split(";")
  return [int(line[0]), line[1]]

def parse_floors(n, cube):
  floors = []
  for i in range(0, n*n*n, n*n):
    floor = cube[i:(i+n*n)]
    floors.append(format_floor(n, floor))
  return floors

def format_floor(n, floor):
  formatted_floor = []
  for i in range(0, n*n, n):
    line = list(floor[i:(i+n)])
    formatted_floor.append(line)
  return formatted_floor

def find_door(floor):
  # parse rows
  for i in range(len(floor[0])):
    if floor[0][i] == ' ':
      return [0, i]
    elif floor[-1][i] == ' ':
      return [len(floor[0]) - 1, i]

  # parse columns
  for i in range(len(floor) - 2):
    if floor[i][0] == ' ':
      return [i, 0]
    elif floor[i][-1] == ' ':
      return [i, len(floor[0]) - 1]

  return [-1, -1]

def find_holes(floor):
  holes = []
  for i in range(len(floor[0])):
    for j in range(len(floor)):
      if floor[i][j] == 'o':
        holes.append([i, j])
  return holes

def make_graph(floor):
  graph = {}
  for i in range(len(floor[0])):
    for j in range(len(floor)):
      if floor[i][j] != '*':
        graph[(i,j)] = []
        if i-1 >= 0 and floor[i-1][j] != '*':
          graph[(i,j)].append((i-1, j))
        if i+1 < len(floor[0]) and floor[i+1][j] != '*':
          graph[(i,j)].append((i+1, j))
        if j-1 >= 0 and floor[i][j-1] != '*':
          graph[(i,j)].append((i, j-1))
        if j+1 < len(floor) and floor[i][j+1] != '*':
          graph[(i,j)].append((i, j+1))
  return graph

# bfs search from node to hole
def find_distance(node, hole, floor_graph):
  # create nodes for the bfs search
  nodes = {}
  for key, value in floor_graph.items():
    nodes[key] = GraphNode(list(key))
  root = tuple(node.coords)
  q = [nodes[root]]
  
  while q:
    current = q.pop(0)
    for adjacent_element in floor_graph[tuple(current.coords)]:
      adjacent_node = nodes[adjacent_element]
      if not adjacent_node.visited:
        adjacent_node.visited = True
        adjacent_node.parent = current
        adjacent_node.distance = current.distance + 1

        if adjacent_node.coords == hole:
          return adjacent_node.distance

        q.append(adjacent_node)
  
  return 0

def find_distances(floor1, floor2, distances):
  holes = find_holes(floor2)
  updated_distances = []
  # convert floor into a searchable graph for pathfinding
  floor_graph = make_graph(floor1)
  for node in distances:
    for hole in holes:
      new_distance = find_distance(node, hole, floor_graph)
      updated_distances.append(Node(hole, new_distance + node.distance + 1))
  return updated_distances

def find_exit(end, distances, floor):
  updated_distances = []
  floor_graph = make_graph(floor)
  for node in distances:
    new_distance = find_distance(node, end, floor_graph)
    updated_distances.append(Node(end, new_distance + node.distance + 1))
  return updated_distances

def find_min(distances):
  if not distances:
    return 0
  min_distance = MAX_NUM
  for node in distances:
    if node.distance < min_distance:
      min_distance = node.distance
  return min_distance

# begin main ----------

f = open(sys.argv[1], 'r')

for line in f:
  n, cube = parse_line(line)
  floors = parse_floors(n, cube)
  start = find_door(floors[0])
  end = find_door(floors[-1])

  distances = []
  distances.append(Node(start))

  for i in range(1, len(floors)):
    distances = find_distances(floors[i-1], floors[i], distances)
  distances = find_exit(end, distances, floors[-1])

  print find_min(distances)

f.close()