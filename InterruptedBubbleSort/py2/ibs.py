# interrupted bubble sort py soln for codeeval by steven a dunn

import sys

def bubble_sort(nums, iterations):
    n = 0
    while n < iterations:
        for i in range(0, len(nums)):
            num = nums[i]
            if i >= len(nums) - 1 - n:
                continue
            next_num = nums[i+1]
            if next_num < num:
                nums[i+1] = num
                nums[i] = next_num
        n += 1
    return nums

for line in open(sys.argv[1], 'r'):
    nums, iterations = line.rstrip().split("|")
    nums = list(map(int, list(nums.rstrip().split(" "))))
    iterations = int(iterations)
    nums = list(map(str, bubble_sort(nums, iterations)))
    print " ".join(nums)