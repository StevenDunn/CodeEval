# Chain Inspection solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

def is_chain_valid(chain):
  element = chain['BEGIN'][0]
  chain['BEGIN'][1] = True

  while element != 'END':
    if chain[element][1] == True:
      return False
    chain[element][1] = True
    element = chain[element][0]

  for key, value in chain.iteritems():
    if value[1] == False:
      return False
  return True

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(';')
  chain = {}

  for entry in line:
    a, b = entry.split('-')
    chain[a] = [b, False]

  result = is_chain_valid(chain)
  if result: print "GOOD"
  else: print "BAD"
