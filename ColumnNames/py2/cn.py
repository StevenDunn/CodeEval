# column names soln in py2 for code eval by steven a dunn

import sys

chars = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]


f = open(sys.argv[1], 'r')
for line in f:
	n = int(line)
	# 702 == ZZ
	if n > 702:
		print n
		# 676 == 26 * 26
		x = n / (676)
		n -= x * (676)
		
		y = n / 26
		z = n % 26
		print x,y, z
		if y == 0:
			x -= 1
			y = 26

		if z == 0:
			y -= 1
			z = 26

		print chars[x-1] + chars[y-1] + chars[z-1]
	elif n > 26:
		y = n / 26
		z = n % 26

		if z == 0:
			y -= 1
			z = 26

		print chars[y-1] + chars[z-1]
	else:
		print chars[n-1]
f.close();