# crime house soln by steven a dunn for code eval

import sys

def parse(line):
  entries = line.strip().split(";")[1].split("|")
  for _ in range(len(entries)):
    entries[_] = entries[_].strip().split()
  return entries

def add(entry, inside, outside):
  if entry == '0':
    inside.append(entry)
    return
  if entry in inside:
    if '0' in outside:
      outside.remove('0')
    else:
      inside.remove(entry)
      inside.append(-1)
  elif entry in outside:
    outside.remove(entry)
    inside.append(entry)
  else:
    inside.append(entry)

def remove(entry, inside, outside):
  if entry == '0':
    outside.append(entry)
    if '0' in inside:
      inside.remove('0')
    return
  if entry in outside:
    if '0' in inside:
      inside.remove('0')
    else:
      outside.remove(entry)
      outside.append(-1)
  elif entry in inside:
    inside.remove(entry)
    outside.append(entry)
  else:
    if '0' in inside:
      inside.remove('0')
    outside.append(entry)

f = open(sys.argv[1], 'r')
for line in f:
  #print line
  entries = parse(line)
  inside, outside = [], []
  for entry in entries:
    #print outside, inside
    if entry[0] == 'E':
      add(entry[1], inside, outside)
    else:
      remove(entry[1], inside, outside)
  #print outside, inside
  if -1 in outside or -1 in inside:
    print "CRIME TIME"
  else:
    print len(inside)
f.close()