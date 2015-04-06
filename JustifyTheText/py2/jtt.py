# justify the text soln in py for code eval by steven a dunn

import sys

def get_longest_substring(line):
    words = line.split(" ")
    line_length = 0
    substring = ""
    for word in words:
        if line_length + len(word) <= 80:
            substring += (word + " ")
            line_length += len(word) + 1
        else:
            break
    return substring.strip()

def split_lines(line):
    lines = []
    while len(line) > 0:
        substring = get_longest_substring(line)
        line = line.replace(substring, '', 1)
        lines.append(substring)
        line = line.strip()
    return lines

def combine_lines(lines):
    formatted_line = ""
    for line in lines:
        #print line
        words = line.split(" ")
        total_length = 0
        for word in words:
            total_length += len(word)
        remaining_length = 80 - total_length
        if len(words) == 1:
            words[0] += (" " * remaining_length)
        else:
            while remaining_length > 0:
                for i in range(0, len(words) - 1):
                    if remaining_length > 0:
                        words[i] += " "
                        remaining_length -= 1

        formatted_line += "".join(words)
        formatted_line += "\n"
    return formatted_line

def format(line):
    return combine_lines(split_lines(line))

f = open(sys.argv[1], 'r')

for line in f:
    line = line.rstrip()
    if len(line) > 80:
        print format(line),
    else:
        print line

f.close()