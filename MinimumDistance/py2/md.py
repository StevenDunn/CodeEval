# minimum distance soln in py2 for code eval by steven a dunn

import sys

def get_distance(addresses, i):
    distance = 0
    for address in addresses:
        distance += abs(address - i)
    return distance

f = open(sys.argv[1], 'r')
for line in f:
    addresses = map(int, line.rstrip().split()[1:])
    addresses.sort()
    min_address, max_address = addresses[0], addresses[-1]
    min_distance = 500000
    for i in range(min_address, max_address):
        distance = get_distance(addresses, i)
        if distance < min_distance:
            min_distance = distance
    print min_distance
f.close()