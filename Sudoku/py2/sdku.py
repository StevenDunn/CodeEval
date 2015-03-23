# Sudoku solution in Python 2 for CodeEval.com by Steven A. Dunn

import math, sys

def get_sum_for_check(N):
  if N is 4:
    return 10
  else:
    return 45

def row_check(N, numbers):
  sum_for_check = get_sum_for_check(N)
  for i in range(0, N * N, N):
    row_sum = 0
    for j in range(0, N):
      row_sum += numbers[i + j]

    if not row_sum is sum_for_check: return False
    return True

def col_check(N, numbers):
  sum_for_check = get_sum_for_check(N)
  for i in range(0, N):
    col_sum = 0
    for j in range(0, N * N, N):
      col_sum += numbers[i + j]

    if not col_sum is sum_for_check: return False
    return True

def grid_check(N, numbers):
  sum_for_check = get_sum_for_check(N)
  sqrt_N = int(math.sqrt(N))
  for grid_x in range(0, sqrt_N):
    for grid_y in range(0, sqrt_N):
      grid_sum = 0
      for i in range(0, sqrt_N):
        for j in range(0, sqrt_N):
          grid_sum += numbers[N * i + j + grid_y * (N * sqrt_N) + grid_x * sqrt_N]

      if not grid_sum is sum_for_check: return False
      return True


for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(';')
  N = int(line[0])
  numbers = map(int, line[1].replace(',', ' ').split(' '))

  if row_check(N, numbers) and col_check(N, numbers) and grid_check(N, numbers): 
    print True
  else:
    print False
