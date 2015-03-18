#string substitution soln in py for code eval by steven a dunn

import sys, re

def parse(line):
    line = line.strip().split(";")
    return line[0], line[1].split(",")

def create_list(text):
    string = []
    for c in text:
        string.append((c, False))
    return string

def not_visited(sub, index, string):
    for element in string[index:index+len(sub)]:
        if element[1] == True:
            return False
    return True

def apply_subs(string, subs, idx):
    first_vals = [i[0] for i in string]
    text = "".join(first_vals)
    search = "(?=" + subs[idx] + ")"
    indices = [i.start() for i in re.finditer(search, text)]
    for index in indices:
        if not_visited(subs[idx], index, string):
            substring = [(i, True) for i in subs[idx+1]]
            string = string[0:index] + substring + string[index+len(subs[idx]):]
            break
    return string

f = open(sys.argv[1], 'r')
for line in f:
    print line
    text, subs = parse(line)
    string = create_list(text)

    idx = 0
    while idx < len(subs):
        print "".join([i[0] for i in string])
        print ",".join([str(i[1]) for i in string])
        string = apply_subs(string, subs, idx)
        idx = idx + 2
    print "".join([i[0] for i in string])
f.close()

"""

import sys
import re

def not_visited(substring, index, visited):
    visited_range = visited[index:index+len(substring)]
    for char in visited_range:
        if char == True:
            return False
    return True

f = open(sys.argv[1], 'r')

for line in f:
    print line
    line = line.strip().split(";")
    text = line[0]
    visited = [False] * len(text)
    subs = line[1].split(",")

    idx = 0
    while idx < len(subs):
        # lookahead regex to detect substrings
        # see: http://stackoverflow.com/questions/4664850/find-all-occurrences-of-a-substring-in-python
        search = "(?=" + subs[idx] + ")"
        indices = [i.start() for i in re.finditer(search, text)]
        for index in indices:
            if not_visited(subs[idx], index, visited):
                text =  text[0:index] + subs[idx+1] + text[index+len(subs[idx]):]
                for i in range(index, index + len(subs[idx])):
                    visited[i] = True
                break
        idx = idx + 2
    print text

f.close()

"""