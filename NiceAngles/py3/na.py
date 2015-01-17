# nice angles soln in py3 for codeeval by steven a dunn

import sys, math

f = open(sys.argv[1], 'r')
for line in f:
    angle = float(line)
    full_degree = math.floor(angle)
    remaining_angle = angle - full_degree
    minutes = math.floor(remaining_angle * 60)
    seconds = math.floor(((remaining_angle * 60) - minutes) * 60)
    sys.stdout.write("%d.%02d'%02d\"\n" % (full_degree, minutes, seconds))
f.close()
