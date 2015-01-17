# big digits py2 soln for code eval by steven a dunn

import sys

def printBigDigits(line):
    rows = ["", "", "", "", ""]
    for i in range(0, len(line)):
        if line[i].isdigit():
            bigPrint(line[i], rows)
    for row in rows:
        print row
    spacer = "-" * len(rows[0])
    print spacer

def bigPrint(char, rows):
    char = int(char)
    if char == 1:
        rows[0] += "--*--";
        rows[1] += "-**--";
        rows[2] += "--*--";
        rows[3] += "--*--";
        rows[4] += "-***-";
    elif char == 2:
        rows[0] += "***--";
        rows[1] += "---*-";
        rows[2] += "-**--";
        rows[3] += "*----";
        rows[4] += "****-";
    elif char == 3:
        rows[0] += "***--";
        rows[1] += "---*-";
        rows[2] += "-**--";
        rows[3] += "---*-";
        rows[4] += "***--";
    elif char == 4:
        rows[0] += "-*---";
        rows[1] += "*--*-";
        rows[2] += "****-";
        rows[3] += "---*-";
        rows[4] += "---*-";
    elif char == 5:
        rows[0] += "****-";
        rows[1] += "*----";
        rows[2] += "***--";
        rows[3] += "---*-";
        rows[4] += "***--";
    elif char == 6:
        rows[0] += "-**--";
        rows[1] += "*----";
        rows[2] += "***--";
        rows[3] += "*--*-";
        rows[4] += "-**--";
    elif char == 7:
        rows[0] += "****-";
        rows[1] += "---*-";
        rows[2] += "--*--";
        rows[3] += "-*---";
        rows[4] += "-*---";
    elif char == 8:
        rows[0] += "-**--";
        rows[1] += "*--*-";
        rows[2] += "-**--";
        rows[3] += "*--*-";
        rows[4] += "-**--";
    elif char == 9:
        rows[0] += "-**--";
        rows[1] += "*--*-";
        rows[2] += "-***-";
        rows[3] += "---*-";
        rows[4] += "-**--";
    elif char == 0:
        rows[0] += "-**--";
        rows[1] += "*--*-";
        rows[2] += "*--*-";
        rows[3] += "*--*-";
        rows[4] += "-**--";
    else:
        pass
    return rows

f = open(sys.argv[1], 'r')
for line in f:
    printBigDigits(line)
f.close()