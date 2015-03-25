# locks soln in py3 for code eval by steven a dunn

import sys

OPEN = False
CLOSED = True

UNLOCKED = False
LOCKED = True

class Door:
    def __init__(self):
        self.lock = UNLOCKED
        self.door = OPEN

    def close(self):
        self.lock = LOCKED
        self.door = CLOSED

    def toggle_lock(self):
        self.lock = not self.lock

def locks(line):
    line = list(map(int, line.rstrip().split(' ')))
    num_locks, repetitions = line[0], line[1]
    locks = [Door() for i in range(num_locks)]

    for n in range(0, repetitions-1):
        for x in range(0, num_locks):
            if (x+1) % 2 == 0:
                locks[x].close()
            if (x+1) % 3 == 0:
                locks[x].toggle_lock()
    # final repetition
    locks[-1].toggle_lock()

    num_unlocked = 0
    for lock in locks:
        if lock.lock == UNLOCKED:
            num_unlocked += 1
    print (num_unlocked)


f = open(sys.argv[1], 'r')
for line in f:
    locks(line)
f.close()