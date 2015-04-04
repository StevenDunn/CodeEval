# number operations soln in py2 for code eval by steven a dunn

import sys, itertools

def sums_to_42(perms):
    for perm in perms:
        perm = list(perm)
        result = [perm.pop()]
        while perm:
            x = perm.pop()
            new_result = []
            for val in result:
                a, b, c = val + x, val - x, val * x
                new_result.append(a)
                new_result.append(b)
                new_result.append(c)
            result = new_result[:]
        if 42 in new_result:
            return True
    return False


f = open(sys.argv[1], 'r')
for line in f:
    nums = map(int, line.rstrip().split(" "))
    perms = list(itertools.permutations(nums, 5))
    if sums_to_42(perms):
        print "YES"
    else:
        print "NO"
f.close()