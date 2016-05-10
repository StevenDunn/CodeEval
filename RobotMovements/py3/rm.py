# robot movements soln in py3 for code eval by steven a dunn

import sys

paths = 0

class Node: 
	visited = False 
	is_end = False 
	link1 = None
	link2 = None
	link3 = None
	link4 = None

n1 = Node()  
n2 = Node()  
n3 = Node() 
n4 = Node()  
n5 = Node()  
n6 = Node()  
n7 = Node()  
n8 = Node()  
n9 = Node()  
n10 = Node()  
n11 = Node()  
n12 = Node()  
n13 = Node()  
n14 = Node()  
n15 = Node()  
n16 = Node()  

def create_grid():
	global n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16

	n1.link1 = n2;
	n1.link2 = n5;

	n2.link1 = n3;
	n2.link2 = n6;
	n2.link3 = n1;

	n3.link1 = n4;
	n3.link2 = n7;
	n3.link3 = n2;

	n4.link2 = n8;
	n4.link3 = n3;

	n5.link1 = n6;
	n5.link2 = n9;
	n5.link4 = n1;

	n6.link1 = n7;
	n6.link2 = n10;
	n6.link3 = n5;
	n6.link4 = n2;

	n7.link1 = n8;
	n7.link2 = n11;
	n7.link3 = n6;
	n7.link4 = n3;

	n8.link2 = n12;
	n8.link3 = n7;
	n8.link4 = n4;

	n9.link1 = n10;
	n9.link2 = n13;
	n9.link4 = n5;

	n10.link1 = n11;
	n10.link2 = n14;
	n10.link3 = n9;
	n10.link4 = n6;

	n11.link1 = n12;
	n11.link2 = n15;
	n11.link3 = n10;
	n11.link4 = n7;

	n12.link2 = n16;
	n12.link3 = n11;
	n12.link4 = n8;

	n13.link1 = n14;
	n13.link4 = n9;

	n14.link1 = n15;
	n14.link3 = n13;
	n14.link4 = n10;

	n15.link1 = n16;
	n15.link3 = n14;
	n15.link4 = n11;

	n16.link3 = n15;
	n16.link4 = n12;
	n16.is_end = True;

	start = n1;
	return start; 

def find_paths(node):
	global paths

	if node.is_end == True:
		paths += 1
		return

	if node.visited == True:
		return

	node.visited = True

	if node.link1 != None:
		find_paths(node.link1)
	if node.link2 != None:
		find_paths(node.link2)
	if node.link3 != None:
		find_paths(node.link3)
	if node.link4 != None: 
		find_paths(node.link4)

	node.visited = False
	return


start = create_grid()
find_paths(start)
print(paths)