# juggling with zeros solution in py3 for code eval by steven a dunn

import sys

def ones(seq):
    result = ""
    for i in range(0, len(seq)):
        result += "1"
    return result

f = open(sys.argv[1], 'r')
for line in f:
    tokens = line.rstrip().split()
    binary = ""
    for i in range(0, len(tokens), 2):
        flag = tokens[i]
        seq = tokens[i+1]
        if flag == "00":
            binary += ones(seq)
        else:
            binary += seq
    print (int(binary, 2))
f.close()