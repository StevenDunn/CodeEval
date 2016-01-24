# crime house soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
  entries = line.strip().split(";")[1].strip().split("|")
  count, ambig, within = 0, 0, []
  print line.strip()
  for entry in entries:
    move, crim = entry.split()
    print move, crim
    if move == 'E':
      if crim != '0':
        if not crim in within:
          within.append(crim)
          count += 1
        else:
          ambig -= 1
      else:
        ambig += 1
    else: 
      if crim != '0':
        if crim in within:
          within.remove(crim)
        count -= 1
      else:
        ambig += 1
    print within, count, ambig
  print count + ambig
  print
f.close()