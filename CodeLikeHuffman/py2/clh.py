# code like huffman soln for code eval by steven a dunn

import sys
from collections import defaultdict

def parse_input(line):
	line = list(line.strip())
	nodes = defaultdict(float)
	total_count = 0
	for c in line:
		nodes[c] += 1
		total_count += 1
	nodes = sorted(nodes.items(), reverse=False, key=lambda x: (x[1], x[0]))
	nodes = [(i[0], i[1]/total_count) for i in nodes]
	return nodes

def get_lowest(leaf_nodes, internal_nodes):
	if leaf_nodes and internal_nodes:
		if leaf_nodes[0][1] < internal_nodes[0][1]:
			return leaf_nodes.pop(0)
		else:
			return internal_nodes.pop(0)
	elif leaf_nodes:
		return leaf_nodes.pop(0)
	elif internal_nodes:
		return internal_nodes.pop(0)

f = open(sys.argv[1], 'r')
for line in f:
	leaf_nodes = parse_input(line)
	internal_nodes = []
	while len(leaf_nodes) + len(internal_nodes) > 1:
		node1 = get_lowest(leaf_nodes, internal_nodes)
		node2 = get_lowest(leaf_nodes, internal_nodes)
		internal_nodes.append((node1[0]+node2[0], node1[1]+node2[1], node1, node2))
	tree = []
	if leaf_nodes:
		tree = leaf_nodes
	else:
		tree = internal_nodes
	print tree
f.close()