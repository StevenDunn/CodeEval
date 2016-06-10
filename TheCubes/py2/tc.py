# the cubes soln in py2 for code eval by steven a dunn

import sys

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
  for i in range(len(floor[0])):
    if floor[0][i] == ' ':
      return [0, i]
    elif floor[-1][i] == ' ':
      return [len(floor[0]) - 1, i]
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

def find_distances(nodes, holes, distances):
  updated_distances = []
  for node in nodes:
    for hole in holes:
      updated_distances.append(find_distance(node, hole))

  
  return holes, updated_distances

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
  line = line.strip().split(";")
  n, cube = int(line[0]), line[1]
  floors = parse_floors(n, cube)
  start = find_door(floors[0])
  end = find_door(floors[-1])
  src = [start]

  for i in range(1, len(floors)):
    dst = find_holes(floor2)
    src, distances = find_distances(src, dst, distances)
    #print "found distance for floor", i
  #distances = find_exit(end, distances, floors[-1])

  print find_min(distances)

f.close()