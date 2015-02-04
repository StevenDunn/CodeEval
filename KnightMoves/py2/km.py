# knight moves soln in py2 for code eval by steven a dunn

import sys

convert = {
    "a" : 1,
    "b" : 2,
    "c" : 3,
    "d" : 4,
    "e" : 5,
    "f" : 6,
    "g" : 7,
    "h" : 8
}

reverse_convert = {
    1 : "a",
    2 : "b",
    3 : "c",
    4 : "d",
    5 : "e",
    6 : "f",
    7 : "g",
    8 : "h"
}

def valid(i):
    if i >= 1 and i <= 8:
        return True
    return False

def get_moves(c, n):
    col = convert[c]
    row = int(n)

    possible_moves = [(col-2,row-1), (col-2,row+1), (col-1,row-2), (col-1,row+2), (col+1,row-2), (col+1,row+2), (col+2,row-1), (col+2,row+1)]

    result = []
    for move in possible_moves:
        if valid(move[0]) and valid(move[1]):
            result.append(move)
    return result

def format(moves):
    formatted_moves = []
    for move in moves:
        c = reverse_convert[move[0]]
        formatted = c + str(move[1])
        formatted_moves.append(formatted)
    return formatted_moves

f = open(sys.argv[1], 'r')

for line in f:
    c = line[0]
    n = line[1]

    moves = get_moves(c, n)
    formatted_moves = format(moves)

    print " ".join(formatted_moves)

f.close()