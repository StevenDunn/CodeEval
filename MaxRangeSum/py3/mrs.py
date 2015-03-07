# max range sum py2 soln for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    line = line.strip().split(";")
    n, vals = [int(line[0]), [int(x) for x in line[1].split()]]

    max_gain = -101
    for i in range(0, len(vals) - n + 1):
        sub_gain = sum(vals[i:i+n])
        if sub_gain > max_gain:
            max_gain = sub_gain

    if max_gain > 0:
        print (max_gain)
    else:
        print (0)
f.close()