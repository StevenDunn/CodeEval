# justify the text soln in py for code eval by steven a dunn

import sys

def space(line):
    length = len(line)
    words = line.split()
    for i in range(0, len(words) - 1):
        words[i] += " "
    length_delta = 80 - length
    word_idx = 0
    while length_delta >= 0:
        words[word_idx] += " "
        word_idx += 1
        word_idx %= len(words) - 1
        length_delta -= 1

    return "".join(words)

f = open(sys.argv[1], 'r')
for line in f:
    words = line.rstrip().split()
    line_length = 0
    line = ""
    for i in range(0, len(words)):
        if len(words[i]) + line_length <= 80:
            line += words[i] + " "
            line_length += len(words[i]) + 1
        else:
            print space(line).rstrip()
            line = words[i] + " "
            line_length = len(words[i]) + 1
    print line.rstrip()
f.close()