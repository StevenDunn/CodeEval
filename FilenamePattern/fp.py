# filename pattern soln in py for codeeval by steven a dunn
import sys
import re

f = open(sys.argv[1], 'r')

for line in f:
    line = line.split()
    pattern = line[0]
    terms = line[1:-1]

    pattern = pattern.replace(".", "\.")
    pattern = pattern.replace("*", ".*")
    pattern = pattern.replace("?", ".")
    pattern += "$"

    pattern = re.compile(pattern)

    results = []
    for term in terms:
        if pattern.match(term):
            results.append(term)

    if not results:
        print "-"
    else:
        print " ".join(results)
f.close()