# Word to Digit solution in Python 2 for CodeEval.com by Steven A. Dunn

def convert(word):
  if word == "one": return 1
  elif word == "two": return 2
  elif word == "three": return 3
  elif word == "four": return 4
  elif word == "five": return 5
  elif word == "six": return 6
  elif word == "seven": return 7
  elif word == "eight": return 8
  elif word == "nine": return 9
  elif word == "zero": return 0
  else: return -1

import sys

for line in open(sys.argv[1], 'r'):
  line = line.strip('\n').split(';')
  for word in line:
    sys.stdout.write(str(convert(word)))
  print
