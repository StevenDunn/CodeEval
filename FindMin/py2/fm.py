# find min soln in py for codeeval by steven a dunn

import sys, collections, heapq

f = open(sys.argv[1], 'r')
for line in f:
    line = line.rstrip().split(",")
    numbers = [int(x) for x in line]
    n, k, a, b, c, r = numbers

    m = [a]
    for i in range(1, k):
        m.append((b * m[i-1] + c) % r)

    if n > (k + k + 1):
        n = k + (n - k) % (k + 1)

    window = collections.Counter(m)
    missing = list([x for x in range(k+1) if not window[x]])
    heapq.heapify(missing)

    for i in range(k, n):
        m.append(heapq.heappop(missing))
        window[m[i]] += 1
        window[m[i-k]] -= 1
        if not window[m[i-k]]:
            heapq.heappush(missing, m[i-k])

    print m[n-1]
f.close()