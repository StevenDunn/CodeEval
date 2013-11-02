# Query Board solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

board = []
for i in range(0, 256):
  board.append([0]*256)

def parseCommand(command, param1, param2):
  param1 = int(param1)
  if param2: param2 = int(param2)
  sum = 0
  
  if command == "SetRow":
    for i in range(0, 256):
      board[i][param1] = param2
  elif command == "SetCol":
    for j in range(0, 256):
      board[param1][j] = param2
  elif command == "QueryRow":
    for i in range(0, 256):
      sum += board[i][param1]
    print sum
  elif command == "QueryCol":
    for j in range(0, 256):
      sum += board[param1][j]
    print sum
  

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  command = line[0]
  param1 = line[1]
  param2 = ""
  if len(line) > 2: param2 = line[2]

  parseCommand(command, param1, param2)
