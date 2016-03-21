# not so clever solution in py3 for code eval by steven a dunn

import sys

def format(line):
	line = line.split(" | ")
	arr = list(map(int, line[0].split()))
	n = int(line[1])
	return arr, n

def stupid_sort(arr):
	for i in range(len(arr) - 1):
		if arr[i] > arr[i+1]:
			temp = arr[i]
			arr[i] = arr[i+1]
			arr[i+1] = temp
			break
	return arr

f = open(sys.argv[1], 'r')
for line in f:
	arr, n = format(line)
	for it in range(n):
		arr = stupid_sort(arr)
	print (" ".join(list(map(str, arr))))
f.close()