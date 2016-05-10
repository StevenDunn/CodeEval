# string searching py2 solution for code eval by steven a dunn

import sys

def search(src, query):
	query_idx = 0
	i = 0
	if query == "*":
		return "true"
	while i < len(src) and query_idx < len(query):
		if query[query_idx] == '*':
			query_idx += 1
			# terminal asterisk
			if query_idx == len(query):
				if src[i-1] == query[query_idx-2]:
					return "true"
				else:
					return "false"
			while i < len(src) and src[i] != query[query_idx]:
				i += 1
		if src[i] == query[query_idx]:
			query_idx += 1
		else:
			query_idx = 0
		if query_idx == len(query):
			return "true"
		i += 1
	return "false"

f = open(sys.argv[1], 'r')
for line in f:
	src, query = line.strip().split(",")
	src = src.replace("*", "@")
	query = query.replace("\*", "@")
	print search(src, query)
f.close()
