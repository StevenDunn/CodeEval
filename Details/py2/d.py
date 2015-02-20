# Details soln in py2 for code eval by Steven A Dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    lines = line.strip().split(",")
    dots = []
    for entry in lines:
        dots.append(entry.count("."))
    print min(dots)
f.close()