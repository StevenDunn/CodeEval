# word chain py2 soln for code eval by steven a dunn

import sys

class Node:
    def __init__(self, letter):
        self.name = letter
        self.links = {}
        self.link_count = {}

    def add(self, node):
        if node.name in self.links:
            self.link_count[node.name] += 1
        else:
            self.link_count[node.name] = 1
            self.links[node.name] = node

    def get_longest_chain(self):
        length = 0

        for name, count in self.link_count.items():
            if count > 0:
                self.link_count[name] -= 1
                length = max([length, self.links[name].get_longest_chain() + 1])
                self.link_count[name] += 1
        return length

f = open(sys.argv[1], 'r')
for line in f:
    words = line.rstrip().split(',')

    # create a graph of letters
    nodes = {}
    for word in words:
        start_letter = word[0]
        if not start_letter in nodes:
            nodes[start_letter] = Node(start_letter)

        end_letter = word[-1]
        if not end_letter in nodes:
            nodes[end_letter] = Node(end_letter)

        # create an edge between the start letter and the end letter
        nodes[start_letter].add(nodes[end_letter])

    chain_length = 0
    for letter, node in nodes.items():
        longest_chain = node.get_longest_chain()
        if longest_chain > chain_length:
            chain_length = longest_chain

    if chain_length <= 1:
        print ("None")
    else:
        print (chain_length)
f.close()