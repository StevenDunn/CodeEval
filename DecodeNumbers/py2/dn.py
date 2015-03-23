# Decode Numbers solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n')
  
  result = None
  if len(line) == 1 and not line[0] == '0':
    print 1
    continue
  if len(line) == 2:
    val = int(line)
    if line[0] == '0' or val > 26:
      print 0
      continue
    if line[1] == '0': 
      print 1
      continue
    else: 
      print 2
      continue

  count = 0
  for i in range(0, len(line) - 1):
    sub = line[i:i+2]
    if sub[0] == '0' or sub[1] == '0':
      count += 1
      continue
    val = int(sub)
    if val > 26: count += 1
    else: count += 2

  print count - (len(line) - 2)
