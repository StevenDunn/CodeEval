# point in circle py2 soln for code eval by steven a dunn

import sys, math

f = open(sys.argv[1], 'r')
for line in f:
    line = line.rstrip().split(";")

    # cryptic parsing follows
    center = line[0].split(",")
    center[0] = center[0].split(",")[0].split("(")
    center_x = float(center[0][1])
    center_y = float(center[1][0:-1])

    radius = float(line[1].split(":")[1])

    point = line[2].split(":")[1].split(",")
    point_x = float(point[0][2:])
    point_y = float(point[1][:-1])

    if (math.sqrt( (center_x - point_x) * (center_x - point_x) + (center_y - point_y) * (center_y - point_y) ) > radius):
        print "false"
    else:
        print "true"
f.close()