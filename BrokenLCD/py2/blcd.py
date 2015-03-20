# broken lcd soln in py2 for code eval by steven a dunn

import sys

# each display from 0 to 9, plus the decimal point
numbers = [0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110, 0b00000001]

f = open(sys.argv[1], 'r')
for line in f:
    displays, number = line.split(";")
    displays = displays.split(" ")
    number = number.strip()

    converted_numbers = []
    for i in range(0, len(number)):
        if number[i] != ".":
            converted_numbers.append(numbers[int(number[i])])
        if number[i] == ".":
            converted_numbers[i-1] += 0b00000001

    did_print = False
    print "displays size: ", len(displays), "converted_numbers size: ", len(converted_numbers)
    for i in range(0, len(displays) - len(converted_numbers) + 1):
        match = 0
        for j in range(0, len(converted_numbers)):
            print "i: ", i, "j: ", j
            print displays[i+j];
            print int(displays[i+j], 2)
            print converted_numbers[j]
            print int(displays[i+j], 2) & converted_numbers[j]
            if int(displays[i+j], 2) & converted_numbers[j] != converted_numbers[j]:
                break
            else:
                match += 1
        if match == len(converted_numbers):
            print 1
            did_print = True
            break
    if not did_print:
        print 0
f.close()