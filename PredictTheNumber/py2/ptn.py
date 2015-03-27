# predict the number soln in py2 for code eval by steven a dunn

import sys

seq = [0, 1]

def calculate(n):
    x = 2
    while x <= n:
        x *= 2
    return x/2

f = open(sys.argv[1], 'r')
for line in f:
    n = int(line)
    x = calculate(n)
    offset = 0
    while n > 0:
        n -= x
        offset += 1
        x = calculate(n)
    print offset % 3
f.close()