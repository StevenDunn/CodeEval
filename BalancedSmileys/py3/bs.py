# balanced smileys soln in py3 for code eval by steven a dunn

import sys

def is_balanced(line):
    if line == "":
        return "YES"

    line = line.replace(":)", "}").replace(":(", "{")

    min_val = 0
    max_val = 0
    for i in range(0, len(line)):
        c = line[i]
        if c == '(':
            min_val += 1
            max_val += 1
        elif c == ')':
            min_val -= 1
            max_val -= 1
            if max_val < 0:
                return "NO"
        elif c == '{':
            max_val += 1
        elif c == '}':
            min_val -= 1

    if min_val <= 0 and 0 <= max_val:
        return "YES"
    return "NO"

f = open(sys.argv[1], 'r')
for line in f:
    print (is_balanced(line))
f.close()