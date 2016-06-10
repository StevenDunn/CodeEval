# crime house soln by steven a dunn for code eval

import sys

def parse(line):
  entries = line.strip().split(";")[1].split("|")
  for _ in range(len(entries)):
    entries[_] = entries[_].strip().split()
  return entries

f = open(sys.argv[1], 'r')
for line in f:
  print line
  entries = parse(line)
  inside, outside = [], []
  anon_enters, anon_exits = set(), set()
  for i in range(len(entries)):
    entry = entries[i]
    if entry[0] == 'E':
      if entry[1] == '0':
        anon_enters.add(i)
    else:
      if entry[1] == '0':
        anon_exits.add(i)
f.close()