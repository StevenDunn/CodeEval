#following integer soln in py for code eval by steven a dunn

import sys

def find_largest(digits):
    largest_digit = digits[0]
    index = 0

    for i in range(len(digits)):
        if digits[i] >= largest_digit:
            largest_digit = digits[i]
            index = i

    return index

def percolate(digits, largest_index):
    if largest_index > 0:
        digits[largest_index], digits[largest_index-1] = digits[largest_index-1], digits[largest_index]
    else:
        #count the zeros
        #remove zeros
        #sort
        #add zero count + 1 to the num
        zero_count = 0

        print "need to expand number"
    return int(''.join(digits))



f = open(sys.argv[1], 'r')

for line in f:
    digits = list(line)
    largest_index = find_largest(digits)
    num = percolate(digits, largest_index)
    print num
f.close()