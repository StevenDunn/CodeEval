# lettercase percentage ratio soln in py3 for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    upper_count = 0.0
    lower_count = 0.0

    chars = list(line.rstrip())
    for char in chars:
        if char.isupper():
            upper_count += 1
        elif char.islower():
            lower_count += 1

    total_count = upper_count + lower_count
    upper_percent = (upper_count / total_count) * 100.0
    lower_percent = (lower_count / total_count) * 100.0

    sys.stdout.write("lowercase: %.2f uppercase: %.2f \n" % (lower_percent, upper_percent))
f.close()