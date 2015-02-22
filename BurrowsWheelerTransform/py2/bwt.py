# Burrows-Wheeler Transform py2 soln by Steven A Dunn for Code Eval

import sys

def add(result, entry):
    for i in range(0, len(result)):
        result[i] += entry[i][-1]
    return result

f = open(sys.argv[1], 'r')
for line in f:
    line = line.strip()[0:-1]
    entry = list(line)
    N = len(entry)
    result = [""] * N
    sorted_result = [""] * N
    for i in range(0, N):
        result = add(result, entry)
        sorted_result = result[:]
        sorted_result.sort()
        entry = sorted_result
    for value in result:
        if value[-1] == "$":
            print value
            break
f.close()