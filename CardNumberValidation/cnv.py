#card number validation soln in py for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

for line in f:
    line = line.strip()
    line = line[::-1]
    line = line.replace(" ", "")

    sum = 0
    for _ in range(len(line)):
        char = line[_]
        digit = int(char)
        if (_ + 1) % 2 == 0:
            digit *= 2
            if digit > 9:
                digit = str(digit)
                digit_1 = int(digit[0])
                digit_2 = int(digit[1])
                digit = digit_1 + digit_2
        sum += digit
    if sum % 10 == 0:
        print 1
    else:
        print 0

f.close()