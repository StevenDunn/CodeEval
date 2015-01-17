# delta time soln in py for codeeval by steven a dunn

import sys
from datetime import datetime

f = open(sys.argv[1], 'r')

for line in f:
    line = line.rstrip().split()
    FMT = '%H:%M:%S'
    date1 = datetime.strptime(line[0], FMT)
    date2 = datetime.strptime(line[1], FMT)

    if date1 > date2:
        tdelta = date1 - date2
    else:
        tdelta = date2 - date1

    hours, rem = divmod(tdelta.seconds, 3600)
    minutes, seconds = divmod(rem, 60)

    if hours < 10:
        hours = "0" + str(hours)
    if minutes < 10:
        minutes = "0" + str(minutes)
    if seconds < 10:
        seconds = "0" + str(seconds)

    print str(hours) + ":" + str(minutes) + ":" + str(seconds)
f.close()