# Capitalize Words solution in Python 3 for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  for word in line:
    word = word[0].upper() + word[1:]
    sys.stdout.write(word + " ")
  print()
