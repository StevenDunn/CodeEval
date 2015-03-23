# Pangrams solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys, string

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').lower()
  alphabet = set(string.ascii_lowercase)
  missing_letters = alphabet - set(line)
 
  if len(missing_letters) == 0: print "NULL"
  else:
    missing_letters = list(missing_letters)
    missing_letters.sort()
    for i in missing_letters:
      sys.stdout.write(i)
    print
