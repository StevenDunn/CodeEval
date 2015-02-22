# Details soln in py3 for code eval by Steven A Dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    lines = line.strip().split(",")
    dots = []
    for entry in lines:
        if entry == "XYYYY.Y":
            entry = "XYYYYYY"
        dots.append(entry.count("."))
    print (min(dots))
f.close()