# city blocks flyover soln in py3 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    x, y = line.rstrip().split(' ')

    x = list(map(int, x[1:-1].split(",")))
    y = list(map(int, y[1:-1].split(",")))

    xs = list(zip(x, x[1:]))
    ys = list(zip(y, y[1:]))

    m = y[-1]/float(x[-1])

    total = 0

    for i in xs:
        for j in ys:
            if not (m * i[0] >= j[1] or m * i[1] <= j[0]):
                total += 1
    print (total)
f.close()