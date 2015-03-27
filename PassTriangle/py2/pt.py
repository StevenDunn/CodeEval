# pass triangle soln in py2 for code eval by steven a dunn

import sys

def calculate_sum(line, sums):
    line_numbers = map(int, line.split())
    if not sums:
        sums = line_numbers
        return sums

    new_sums = []
    for i in range(0, len(sums) - 1):
        max_num = 0
        if sums[i] > sums[i + 1]:
            max_num = sums[i]
        else:
            max_num = sums[i + 1];
        new_sums.append(max_num + line_numbers[i])
    sums = new_sums
    return sums

f = open(sys.argv[1], 'r')
line_stack = []
for line in f:
    line_stack.append(line)
f.close()

sums = []
while line_stack:
    line = line_stack.pop()
    sums = calculate_sum(line, sums)
print sums[0]
