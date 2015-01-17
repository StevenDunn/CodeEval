# Morse Code solution in Python 3 for CodeEval.com by Steven A. Dunn

morseDict = {
  ".-" : 'A',
  "-..." : 'B',
  "-.-." : 'C',
  "-.." : 'D',
  "." : 'E',
  "..-." : 'F',
  "--." : 'G',
  "...." : 'H',
  ".." : 'I',
  ".---" : 'J',
  "-.-" : 'K',
  ".-.." : 'L',
  "--" : 'M',
  "-." : 'N',
  "---" : 'O',
  ".--." : 'P',
  "--.-" : 'Q',
  ".-." : 'R',
  "..." : 'S',
  "-" : 'T',
  "..-" : 'U',
  "...-" : 'V',
  ".--" : 'W',
  "-..-" : 'X',
  "-.--" : 'Y',
  "--.." : 'Z',

  ".----" : '1',
  "..---" : '2',
  "...--" : '3',
  "....-" : '4',
  "....." : '5',
  "-...." : '6',
  "--..." : '7',
  "---.." : '8',
  "----." : '9',
  "-----" : '0' }

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  for i in line:
    if i == '':
      sys.stdout.write(' ');
    else:
      sys.stdout.write(morseDict[i])
  print()
