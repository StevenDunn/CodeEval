# black card soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
  line = line.strip().split(" | ")
  people, n = line[0].split(), int(line[1]) - 1
  
  while len(people) > 1:
    idx = n % len(people)
    del people[idx]
  print people[0]

f.close()