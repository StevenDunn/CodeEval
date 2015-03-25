# roman and arabic soln in py3 for code eval by steven a dunn

import sys

def roman_to_arabic(num):
    result = 0
    if num == "I":
     result = 1
    elif num == "V":
        result = 5
    elif num == "X":
        result = 10
    elif num == "L":
        result = 50
    elif num == "C":
        result = 100
    elif num == "D":
        result = 500
    elif num == "M":
        result = 1000
    return result

def convert(pair):
    a, r = int(pair[0]), roman_to_arabic(pair[1])
    return a * r

def greater(x, y):
    x = roman_to_arabic(x)
    y = roman_to_arabic(y)
    return x > y

def calculate(digits, pairs):
    total = 0
    prev_r = pairs[0][-1]
    for i in range(0, len(digits)):
        if i == len(digits) - 1:
            total += digits[i]
            continue
        curr_r = pairs[i][-1]
        next_r = pairs[i+1][-1]

        if greater(next_r, curr_r):
            total -= digits[i]
        else:
            total += digits[i]
    return total


f = open(sys.argv[1], 'r')
for line in f:
    line = line.rstrip()
    pairs = []
    digits = []
    for i in range(0,len(line), 2):
        pair = line[i:i+2]
        pairs.append(pair)
        digits.append(convert(pair))
    print (calculate(digits, pairs))
f.close()