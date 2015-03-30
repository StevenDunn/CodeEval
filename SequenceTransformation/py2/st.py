# sequence transformation soln in py2 for code eval by steven a dunn

import sys, re

ZERO_REGEX = r'A+'
ONE_REGEX = r'(A+|B+)'

def is_seq_transform(binary, seq):
    regexes = []
    for i in range(0, len(binary)):
        if binary[i] == '0':
            regexes.append(ZERO_REGEX)
        else:
            regexes.append(ONE_REGEX)
    regex_str = "".join(regexes)
    result = re.match(regex_str, seq)
    if result:
        print "Yes"
    else:
        print "No"

f = open(sys.argv[1], 'r')
for line in f:
    binary, seq = line.rstrip().split(" ")
    is_seq_transform(binary, seq)
f.close()