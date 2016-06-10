#string substitution soln in py for code eval by steven a dunn

import sys, re

def parse(line):
    line = line.rstrip().split(';')
    return line[0], line[1].split(',')

def not_visited(visited, src, occurence):
    for i in range(0, len(src)):
        if occurence + i < len(visited) and visited[occurence + i] == True:
            return False
    return True

def update_string(text, visited, occurence, src, rpl):
    text = text[0:occurence] + rpl + text[occurence + len(src):]
    visited = visited[0:occurence] + ([True] * len(rpl)) + visited[occurence + len(src):] 
    return text, visited

def replace(text, visited, src, rpl):
    occurences = [m.start() for m in re.finditer('(?=' + src + ')', text)]
    for occurence in occurences:
        if not_visited(visited, src, occurence):
            return update_string(text, visited, occurence, src, rpl)
    return text, visited

def format(visited):
    result = ""
    for i in visited:
        if i == False:
            result += "F"
        else:
            result += "T"
    return result

f = open(sys.argv[1], 'r')
for line in f:
    text, subs = parse(line)
    visited = [False] * len(text)
    for i in range(0, len(subs) - 1, 2):
        src, rpl = subs[i], subs[i+1]
        updated_text, visited = replace(text, visited, src, rpl)
        while text != updated_text:
            text = updated_text
            updated_text, visited = replace(text, visited, src, rpl)
    print text
f.close()