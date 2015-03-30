# Lost in Translation soln in Py3 for CodeEval.com by Steven A. Dunn

cipher = {
    'y' : 'a',
    'n' : 'b',
    'f' : 'c',
    'i' : 'd',
    'c' : 'e',
    'w' : 'f',
    'l' : 'g',
    'b' : 'h',
    'k' : 'i',
    'u' : 'j',
    'o' : 'k',
    'm' : 'l',
    'x' : 'm',
    's' : 'n',
    'e' : 'o',
    'v' : 'p',
    'z' : 'q',
    'p' : 'r',
    'd' : 's',
    'r' : 't',
    'j' : 'u',
    'g' : 'v',
    't' : 'w',
    'h' : 'x',
    'a' : 'y',
    'q' : 'z'
}

def decipher(word):
  decryptedWord = ""
  for i in range(0, len(word)):
    decryptedWord += cipher[word[i]]
  return decryptedWord


import sys

for line in open(sys.argv[1], 'r'):
  line = line.strip('\n').split(' ')
  for word in line:
    print (decipher(word), end=" ")
  print()
