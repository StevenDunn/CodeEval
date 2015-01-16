# Beautiful Strings solution in Python 2 for CodeEval.com by Steven A. Dunn

def getCounts(line):
  counts = [0] * 26
  ASCII_ZERO = 97
  for c in line:
    i = ord(c) - ASCII_ZERO
    idx = int(i)
    if idx >= 0 and i < 26:
      counts[idx] += 1
  
  return counts


def getBeauty(counts):
  beauty = 0
  weight = 26
 
  counts.sort()

  for i in range(len(counts) - 1, -1, -1):
    beauty += weight * counts[i]
    weight -= 1

  return beauty



import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').lower()
  counts = getCounts(line)
  beauty = getBeauty(counts)
  print beauty
