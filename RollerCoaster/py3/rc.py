# roller coaster soln in py3 for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    letter_case = True
    line = list(line.rstrip())
    result = ""
    for char in line:
        if char.isalpha():
            if letter_case:
                result += char.upper()
            else:
                result += char.lower()
            letter_case = not letter_case
        else:
            result += char
    print(result)
f.close()