# matrix rotation soln in py3 for codeeval by steven a dunn

import sys, math

f = open(sys.argv[1], 'r')

for line in f:
    matrix = line.rstrip().split(" ")
    n = int(math.sqrt(len(matrix)))

    result = ""
    for j in range(0, n):
        for i in range(n-1, -1, -1):
            result += matrix[(i * n) + j] + " "
    print(result)
f.close()