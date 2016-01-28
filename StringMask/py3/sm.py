#string mask soln in py3 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
  line = line.split()
  text, mask, result = line[0], line[1], ""
  for i in range(0, len(line[0])):
    if mask[i] == "1":
      result += text[i].upper()
    else:
      result += text[i]
  print (result)
f.close()