# Pile of Bricks solution in Py2 for CodeEval.com by Steven A. Dunn

class Hole:
  x = -1
  y = -1

import sys

for line in open(sys.argv[1], 'r'):
  line = line.strip('\n').split("|")

  hole_list = line[0].replace("[", "").replace("]", "").replace(",", " ")
  hole_list = map(int, hole_list.split(" "))
 
  hole = Hole()
  hole.x = abs(hole_list[0] - hole_list[2])
  hole.y = abs(hole_list[1] - hole_list[3])

  bricks_list = line[1]
  bricks_list = bricks_list.replace("(", "").replace(")", "")
  bricks_list = bricks_list.split(";")

  print bricks_list
