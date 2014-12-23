# ip package soln in python2 for codeeval by steven dunn

import sys

for line in open(sys.argv[1], 'r'):
    line = line.strip().split()
    source = line[0]
    destination = line[1]
    package = line[2:-1]

    print source, destination
    print len(package)