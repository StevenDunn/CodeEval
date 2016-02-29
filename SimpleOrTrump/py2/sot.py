# simple or trump soln in py2 for code eval by steven a dunn

import sys

def convert(val):
	if val == 'T':
		return 15
	elif val == 'A':
		return 14
	elif val == 'K':
		return 13
	elif val == 'Q':
		return 12
	elif val == 'J':
		return 11
	else:
		return int(val)

def compare_hands(hands, trump):
	for idx, hand in enumerate(hands):
		if hand[-1] == trump:
			hands[idx] = 'T' + hand[-1]
	val_1, val_2 = convert(hands[0][0:-1]), convert(hands[1][0:-1])
	if val_1 > val_2:
		return -1
	elif val_1 < val_2:
		return 1
	return 0

f = open(sys.argv[1], 'r')
for line in f:
	hands, trump = line.strip(). split(" | ")
	hands = hands.split()
	comp_hands = hands[:]
	comp = compare_hands(comp_hands, trump)
	if comp < 0:
		print hands[0]
	elif comp > 0:
		print hands[1]
	else:
		print hands[0] + " " + hands[1]
f.close()