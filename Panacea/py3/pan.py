# panacea soln in py3 for code eval by steven a dunn

import sys

f = open(sys.argv[1], 'r')
for line in f:
	vir, ant = line.strip().split(" | ")
	vir = [int(x, 16) for x in vir.split()]
	ant = [int(x, 2) for x in ant.split()]
	vir_sum, ant_sum = sum(vir), sum(ant)
	
	if ant_sum >= vir_sum:
		print ("True")
	else:
		print ("False")
f.close()