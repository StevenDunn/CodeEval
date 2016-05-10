# palindromic ranges soln in py3 for code eval by steven a dunn

import sys

def is_palindrome(x):
	x_str = str(x)
	if x_str == x_str[::-1]:
		return True
	return False 

def get_num_ranges(x, y):
	interesting_range_count = 0
	nums = []
	for i in range(x, y+1):
		if is_palindrome(i):
			nums.append(1)
		else:
			nums.append(0)
	for i in range(len(nums)):
		palindrome_count = 0
		for j in range(i, len(nums)):
			if nums[j] == 1:
				palindrome_count += 1
			if palindrome_count % 2 == 0:
				interesting_range_count += 1
	return interesting_range_count

f = open(sys.argv[1], 'r')
for line in f:
	x, y = list(map(int, line.strip().split()))
	print (get_num_ranges(x, y))
f.close()