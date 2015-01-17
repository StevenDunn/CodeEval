# age distribution solution in py2 for codeeval.com by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
    line = int(line.rstrip())
    if line < 0:
        print ("This program is for humans")
    elif line <= 2:
        print ("Still in Mama's arms")
    elif line <= 4:
        print ("Preschool Maniac")
    elif line <= 11:
        print ("Elementary school")
    elif line <= 14:
        print ("Middle school")
    elif line <= 18:
        print ("High school")
    elif line <= 22:
        print ("College")
    elif line <= 65:
        print ("Working for the man")
    elif line <= 100:
        print ("The Golden Years")
    else:
        print ("This program is for humans")
f.close()