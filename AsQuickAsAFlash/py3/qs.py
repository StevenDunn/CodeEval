# as quick as a flash soln for code eval by steven a dunn

import sys

def partition(vals, lo, hi):
	i, j, pivot = lo, hi, vals[lo]
	while True:
		while vals[i] < pivot:
			i += 1
		while vals[j] > pivot:
			j -= 1
		if i >= j:
			return j
		vals[i], vals[j] = vals[j], vals[i]

def quick_sort(vals, lo, hi):
	global pivots
	if lo < hi:
		p = partition(vals, lo, hi)
		pivots += 1
		quick_sort(vals, lo, p-1)
		quick_sort(vals, p+1, hi)

pivots = 0
f = open(sys.argv[1], 'r')
for line in f:
	vals = list(map(int, line.strip().split()))
	quick_sort(vals, 0, len(vals)-1)
	print (pivots)
	pivots = 0
f.close()