# guess the num soln in py3 for codeeval by steven a dunn

import sys

def parse(line):
    line = line.split()
    upper_bound = int(line[0])
    line = line[1:]
    return [upper_bound, line]

def get_midpoint(lower_bound, upper_bound):
    midpoint = (upper_bound - lower_bound)
    if midpoint % 2 == 0:
        midpoint //= 2
    else:
        midpoint = (midpoint + 1)//2
    return lower_bound + midpoint

def guess(lower_bound, upper_bound, guess_update):
    midpoint = get_midpoint(lower_bound, upper_bound)
    if guess_update == "Lower":
        upper_bound = midpoint - 1
    elif guess_update == "Higher":
        lower_bound = midpoint + 1
    else:
        upper_bound = midpoint
    return [lower_bound, upper_bound]

#####

f = open(sys.argv[1], 'r')

for line in f:
    lower_bound = 0
    [upper_bound, line] = parse(line)

    for guess_index in range(len(line)):
        [lower_bound, upper_bound] = guess(lower_bound, upper_bound, line[guess_index])
    print (upper_bound)
f.close()