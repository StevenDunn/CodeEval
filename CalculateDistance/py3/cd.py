# Calculate Distance solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys, math

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n')
  sep = line.find(") (")

  coord1 = list(map(int, line[1:sep].split(',')))
  coord2 = list(map(int, line[sep+3:len(line)-1].split(',')))

  distance = math.sqrt((coord2[0] - coord1[0]) ** 2 + (coord2[1] - coord1[1]) ** 2)
  print(int(distance))
