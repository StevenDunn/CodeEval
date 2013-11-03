# Mixed Content solution in Python 2 for CodeEval.com by Steven A. Dunn

def sift(x):
  global nums
  global words
  
  try: 
    int(x)
    nums.append(x)
  except ValueError:
    words.append(x)


import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(',')

  words = []
  nums = []
  filter(sift, line)

  if len(words) > 0:
    for i in range(0, len(words) - 1):
      sys.stdout.write(words[i] + ",")
    sys.stdout.write(words[-1])

  if len(words) > 0 and len(nums) > 0:
    sys.stdout.write("|")

  if len(nums) > 0:
    for i in range(0, len(nums) - 1):
      sys.stdout.write(nums[i] + ",")
    sys.stdout.write(nums[-1])
  print
