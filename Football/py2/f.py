# football soln in py2 for code eval by steven a dunn

import sys, collections

f = open(sys.argv[1], 'r')
for line in f:
	line = line.strip().split(" | ")
	countries = {}
	team_idx = 0
	for team in line:
		fans = map(int, team.strip().split())
		for fan in fans:
			if fan in countries:
				countries[fan].append(team_idx + 1)
			else:
				countries[fan] = [team_idx + 1]
		team_idx += 1

	countries = collections.OrderedDict(sorted(countries.items()))
	for k, v in countries.iteritems():
		v = map(str, v)
		sys.stdout.write(str(k) + ":" + ",".join(v) + "; ")
	print
f.close()