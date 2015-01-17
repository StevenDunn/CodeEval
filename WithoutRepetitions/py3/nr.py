# without repetitions soln in py3 for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
    line = line.strip()
    new_line = ""
    #print line
    #print len(line)
    if len(line) == 1:
        print(line)
        continue
    else:
        x = 0
        y = 1

        while y < len(line):
            #print line[x], line[y]
            if line[x] != line[y]:
                new_line += line[x]
                if y == len(line) - 1:
                    new_line += line[y]
            else:
                if y == len(line) - 1:
                    new_line += line[x]

            x += 1
            y += 1

        print(new_line)

f.close()