# real fake soln in py3 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
  line = line.strip()
  line = [x for x in line if x != ' ']
  
  cc_sum = 0
  for i in range(0, len(line), 2):
    cc_sum += 2 * int(line[i])
  for i in range(1, len(line), 2):
    cc_sum += int(line[i])
    
  if cc_sum % 10 == 0:
    print ("Real")
  else:
    print ("Fake")
f.close()