# black or white soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
  lines = line.strip().split(" | ")
  #print lines

  # edge case when cars are all single color
  if len(set(''.join(lines))) == 1:
    print "1x1,", line[0]
    continue

  # continually increase the size of the submatrix until same as parent
  sub_dim = 2
  while sub_dim <= len(lines[0]):
    black_sums = []
    sums_idx = 0
    for j in range(len(lines[0]) - sub_dim + 1):
      for i in range(len(lines[0]) - sub_dim + 1):
        # explore submatrix of size sub_dim
        black_sums.append(0)
        for n in range(0, sub_dim):
          for m in range(0, sub_dim):
            #print i+m, j+n
            #print lines[j+n][i+m]
            if lines[j+n][i+m] == '1':
              black_sums[sums_idx] += 1
        sums_idx += 1

    # all submatrices have same number of black cars
    if len(set(black_sums)) == 1:
      print str(sub_dim) + "x"+ str(sub_dim) + ", " + str(black_sums[0])
      break
    sub_dim += 1
f.close()