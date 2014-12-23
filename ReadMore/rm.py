# read more py soln for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
    line = line.strip()
    line_length = len(line)
    if line_length > 55:
        line = line[0:40]
        last_space = line.rfind(" ")
        if last_space != -1:
            line = line[0:last_space]
        line += "... <Read More>"
    print line

f.close()