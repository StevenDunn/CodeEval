# big digits soln in py for code eval by steven a dunn
import sys

def big_print(char, rows):
    char = int(char)
    if char == 1:
        rows[0] += "__*__"
        rows[1] += "_**__"
        rows[2] += "__*__"
        rows[3] += "__*__"
        rows[4] += "_***_"
    elif char == 2:
        rows[0] += "***__"
        rows[1] += "___*_"
        rows[2] += "_**__"
        rows[3] += "*____"
        rows[4] += "****_"
    elif char == 3:
        rows[0] += "***__"
        rows[1] += "___*_"
        rows[2] += "_**__"
        rows[3] += "___*_"
        rows[4] += "***__"
    elif char == 4:
        rows[0] += "_*___"
        rows[1] += "*__*_"
        rows[2] += "****_"
        rows[3] += "___*_"
        rows[4] += "___*_"
    elif char == 5:
        rows[0] += "****_"
        rows[1] += "*____"
        rows[2] += "***__"
        rows[3] += "___*_"
        rows[4] += "***__"
    elif char == 6:
        rows[0] += "_**__"
        rows[1] += "*____"
        rows[2] += "***__"
        rows[3] += "*__*_"
        rows[4] += "_**__"
    elif char == 7:
        rows[0] += "****_"
        rows[1] += "___*_"
        rows[2] += "__*__"
        rows[3] += "_*___"
        rows[4] += "_*___"
    elif char == 8:
        rows[0] += "_**__"
        rows[1] += "*__*_"
        rows[2] += "_**__"
        rows[3] += "*__*_"
        rows[4] += "_**__"
    elif char == 9:
        rows[0] += "_**__"
        rows[1] += "*__*_"
        rows[2] += "_***_"
        rows[3] += "___*_"
        rows[4] += "_**__"
    elif char == 0:
        rows[0] += "_**__"
        rows[1] += "*__*_"
        rows[2] += "*__*_"
        rows[3] += "*__*_"
        rows[4] += "_**__"

    return rows

f = open(sys.argv[1], 'r')

for line in f:
    rows = ["", "", "", "", ""]
    for char in line:
        if char.isdigit():
            rows = big_print(char, rows)
    for row in rows:
        print row
    spacer = ""
    for _ in range(len(rows[0])):
      spacer += "_"
    print spacer

f.close()