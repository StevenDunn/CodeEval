# distinct subsequences soln for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
	seq, sub = line.strip().split(",")
	num_ds = [0] * (len(sub) + 1)
	num_ds[len(sub)] = 1
	for i in range(len(seq)-1, -1, -1):
		for j in range(len(sub)):
			num_ds[j] += int(seq[i] == sub[j]) * num_ds[j+1]
	print num_ds[0]