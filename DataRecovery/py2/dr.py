# data recovery solution in py2 for code eval by steven a dunn

import sys

def find_missing(indices, text_length):
    i_sum = 0;
    for i in indices:
        i_sum += i
    expected_sum = text_length * (text_length + 1) / 2;
    return expected_sum - i_sum;

f = open(sys.argv[1], 'r')
for line in f:
    split_line = line.split(';')
    text = split_line[0].split()
    indices = map(int, split_line[1].split())
    indices.append(find_missing(indices, len(text)))
    for i in xrange(1, len(indices)+1):
        print text[indices.index(i)],
    print
f.close()