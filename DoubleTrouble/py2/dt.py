# double trouble soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:

  half_len = len(line.strip()) / 2
  text_1 = line[0:half_len]
  text_2 = line[half_len:]

  total = 1

  for i in range(0, half_len):
    l_1, l_2 = text_1[i], text_2[i]
    if l_1 == l_2 and l_1 == '*':
      total *= 2
    if l_1 != l_2:
      if (l_1 == 'A' or l_1 == 'B') and (l_2 == 'A' or l_2 == 'B'):
        total = 0
        break
  print total

f.close()