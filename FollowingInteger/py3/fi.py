#following integer soln in py3 for code eval by steven a dunn

import sys
from itertools import permutations

def parse_digits(line):
    digits = "".join(sorted(line.rstrip()))
    remaining = 6 - len(digits)
    padding = "0" * remaining
    return padding + digits

f = open(sys.argv[1], 'r')
for line in f:
    original = int(line)
    digits = parse_digits(line)
    for perm in permutations(digits):
        val = int("".join(perm))
        if val > original:
            print (val)
            break
f.close()