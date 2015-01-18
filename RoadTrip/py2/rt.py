# road trip soln in py2 for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    line = line.rstrip().split(";")
    distances = []
    for entry in line:
        if not entry:
            continue
        distance = int(entry.split(",")[1])
        distances.append(distance)
    distances.sort()

    results = []
    cur_pos = 0
    for distance in distances:
        location = distance - cur_pos
        results.append(location)
        cur_pos = distance
    results = list(map(str, results))
    print ",".join(results)
f.close()