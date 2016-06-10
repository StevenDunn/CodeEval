#ray of light soln in py2 for codeeval by steven a dunn

import sys

room = []
splitters = []

def deserialize(line):
    global splitters

    splitters = []
    line = line.rstrip()
    chunks, chunk_size = len(line), len(line)/10
    room = [line[i:i+chunk_size] for i in range(0, chunks, chunk_size)]
    for index, row in enumerate(room):
        room[index] = list(row)
        splitters_this_row = [i for i, x in enumerate(room[index]) if x == "*"]
        for i in splitters_this_row:
            splitters.append([index, i, False])
    return room

def find_start():
    for i in range(0, 10):
        if room[0][i] == "/" or room[0][i] == "\\":
            return [0, i]
        if room[9][i] == "/" or room[9][i] == "\\":
            return [9, i]
        if room[i][0] == "/" or room[i][0] == "\\":
            return [i, 0]
        if room[i][9] == "/" or room[i][9] == "\\":
            return [i, 9]

def is_forward_slash(x, y):
    return room[x][y] == "/"

def find_direction(x, y):
    if x == 0:
        if is_forward_slash(x, y):
            direction = 225
        else:
            direction = 315
    elif x == 9:
        if is_forward_slash(x, y):
            direction = 45
        else:
            direction = 135
    elif y == 0:
        if is_forward_slash(x, y):
            direction = 45
        else:
            direction = 315
    else:
        if is_forward_slash(x, y):
            direction = 225
        else:
            direction = 135
    return direction

def in_range(n):
    if n >= 0 and n < 10:
        return True
    return  False

def is_wall(x, y):
    if room[x][y] == "#":
        return True
    return False

def does_reflect(x, y):
    if (x == 0 and y == 0) or (x == 0 and y == 9) or (x == 9 and y == 0) or (x == 9 and y == 9):
        return False
    return True

def calculate_reflection(x, y, direction, depth):
    if does_reflect(x, y):
        if direction == 45:
            if x == 0:
                calculate_update(x+1, y, 315, depth - 1)
            else:
                calculate_update(x, y-1, 135, depth - 1)
        elif direction == 225:
            if x == 9:
                calculate_update(x-1, y, 135, depth - 1)
            else:
                calculate_update(x, y+1, 315, depth - 1)
        elif direction == 135:
            if x == 0:
                calculate_update(x+1, y, 225, depth - 1)
            else:
                calculate_update(x, y+1, 45, depth - 1)
        elif direction == 315:
            if x == 9:
                calculate_update(x-1, y, 45, depth - 1)
            else:
                calculate_update(x, y-1, 225, depth - 1)

def is_column(x, y):
    if room[x][y] == "o":
        return True
    else:
        return False

def is_splitter(x, y):
    if room[x][y] == "*":
        return True
    return False

def split(x, y, depth):
    for splitter in splitters:
        if splitter[0] == x and splitter[1] == y and splitter[2] == False:
            splitter[2] = True
            calculate_update(x+1, y-1, 225, depth)
            calculate_update(x+1, y+1, 315, depth)
            calculate_update(x-1, y-1, 135, depth)
            calculate_update(x-1, y+1, 45, depth)

def mark_ray(x, y, direction):
    if room[x][y] == "X":
        return
    if direction == 45 or direction == 225:
        if room[x][y] == "\\":
            room[x][y] = "X"
        elif room[x][y] != "/":
            room[x][y] = "/"
    else:
        if room[x][y] == "/":
            room[x][y] = "X"
        elif room[x][y] != "\\":
            room[x][y] = "\\"

def visited(x, y, direction):
    if direction == 45 or direction == 225:
        if room[x][y] == "/":
            return True
    else:
        if room[x][y] == "\\":
            return True
    return False

def calculate_update(x, y, direction, depth):
    if depth <= 0:
        return
    #print x, y, direction, depth
    if in_range(x) and in_range(y) and not visited(x, y, direction):
        if is_wall(x, y):
            calculate_reflection(x, y, direction, depth+1)
        else:
            if not is_column(x, y):
                if is_splitter(x, y):
                    split(x, y, depth)
                else:
                    mark_ray(x, y, direction)
                    update_ray(x, y, direction, depth)

def update_ray(x,y, direction, depth):
    if direction == 45:
        calculate_update(x-1, y+1, direction, depth - 1)
    elif direction == 225:
        calculate_update(x+1, y-1, direction, depth - 1)
    elif direction == 135:
        calculate_update(x-1, y-1, direction, depth - 1)
    elif direction == 315:
        calculate_update(x+1, y+1, direction, depth - 1)
    else:
        print "error: invalid direction!"

def serialize():
    result = ""
    for line in room:
        result += "".join(line)
    return result

f = open(sys.argv[1], 'r')
for line in f:
    print line
    room = deserialize(line)
    #print room
    x,y = find_start()
    initial_direction = find_direction(x,y)
    depth = 20
    #print x, y, initial_direction, depth
    update_ray(x, y, initial_direction, depth)
    print serialize()
f.close()