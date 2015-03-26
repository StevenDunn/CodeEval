# bats challenge soln in py2 for code eval by steven a dunn

import sys

def too_close(spot, bats, spacing):
    for bat in bats:
        if abs(spot - bat) < spacing:
            return True
    return False

f = open(sys.argv[1], 'r')
for line in f:
    line = line.split()
    length, spacing, bats = int(line[0]) - 6, int(line[1]), list(map(int, line[3:]))
    bats.sort()
    new_bats = 0
    for spot in range (6, length + 1):
        if not too_close(spot, bats, spacing):
            new_bats += 1
            bats.append(spot)
    print (new_bats)
f.close()