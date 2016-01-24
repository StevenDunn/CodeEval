# try to solve it soln in py2 for code eval by steven a dunn

import sys

letters = { 
'a' : 'u',
'b' : 'v',
'c' : 'w',
'd' : 'x',
'e' : 'y',
'f' : 'z',
'g' : 'n',
'h' : 'o',
'i' : 'p',
'j' : 'q',
'k' : 'r',
'l' : 's',
'm' : 't',
'n' : 'g',
'o' : 'h',
'p' : 'i',
'q' : 'j',
'r' : 'k',
's' : 'l',
't' : 'm',
'u' : 'a',
'v' : 'b',
'w' : 'c',
'x' : 'd',
'y' : 'e',
'z' : 'f'
}

f = open(sys.argv[1], 'r')
for line in f:
  line = line.strip().lower()
  for c in line:
    sys.stdout.write(letters[c])
  print
f.close()