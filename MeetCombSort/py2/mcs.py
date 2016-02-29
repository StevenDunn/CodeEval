# meet comb sort soln in py2 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
	nums = map(int, line.strip().split())
	sorted_nums = sorted(nums[:])
	gap = len(nums)
	shrink = 1.25
	iterations = 1

	while gap > 1:
		gap = int(gap/shrink)
		if gap < 1:
			gap = 1

		i = 0

		while i + gap < len(nums):
			if nums[i] > nums[i + gap]:
				nums[i], nums[i+gap] = nums[i+gap], nums[i]
			i += 1

		if nums == sorted_nums:
			break

		iterations += 1
	print iterations
f.close()