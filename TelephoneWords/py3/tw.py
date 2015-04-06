# telephone words soln in py3 for code eval by steven a dunn

import sys

def concat(i, val):
    return i + val

def convert(digit):
    if digit == "0": return "0"
    if digit == "1": return "1"
    if digit == "2": return ["a", "b", "c"]
    if digit == "3": return ["d", "e", "f"]
    if digit == "4": return ["g", "h", "i"]
    if digit == "5": return ["j", "k", "l"]
    if digit == "6": return ["m", "n", "o"]
    if digit == "7": return ["p", "q", "r", "s"]
    if digit == "8": return ["t", "u", "v"]
    if digit == "9": return ["w", "x", "y", "z"]

f = open(sys.argv[1], 'r')
for line in f:
    number = list(line.rstrip())
    number.reverse()

    digit = number.pop()
    result = []
    result.append(convert(digit))
    result = [item for sublist in result for item in sublist]
    while number:
        digit = number.pop()
        values = convert(digit)
        new_result = []
        for val in values:
            concatted = [concat(i, val) for i in result]
            new_result.append(concatted)
        new_result = [item for sublist in new_result for item in sublist]
        result = new_result[:]
    result.sort()
    print (",".join(result))
f.close()