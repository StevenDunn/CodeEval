# stepwise word soln in py2 for code eval by steven a dunn
import sys

f = open(sys.argv[1], 'r')
for line in f:
  line = sorted(line.strip().split(), key=len)
  longest = line[-1]
  max_length = len(longest)
  line = [x for x in line if len(x) == max_length]
  if len(line) > 1:
    longest = line[0]
  for i in range(len(longest)):
    print ('*' * i) + longest[i],
  print
f.close()