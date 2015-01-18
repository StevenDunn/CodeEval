# hidden digits soln in py3 for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    result = ""
    line = list(line)
    for char in line:
        ordVal = ord(char)
        if (ordVal >= 48 and ordVal <= 57):
            result += str(ordVal - 48)
        elif (ordVal >= 97 and ordVal <= 106):
            result += str(ordVal - 97)
    if not result:
        print ("NONE")
    else:
        print (result)
f.close()