# Lowest Common Ancestor solution in Python 2 for CodeEval.com by Steven A. Dunn

class Node:
  def __init__(self):
    left = None
    right = None
    val = 0

def createTree():
  node = Node()
  node.val = 30

  node.left = Node()
  node.left.val = 8
  node.left.left = Node()
  node.left.left.val = 3
  node.left.left.left = None
  node.left.left.left = None
  node.left.right = Node()
  node.left.right.val = 20
  node.left.right.left = Node()
  node.left.right.left.val = 10
  node.left.right.left.left = None
  node.left.right.left.right = None
  node.left.right.right = Node()
  node.left.right.right.left = None
  node.left.right.right.right = None
  node.right = Node()
  node.right.val = 52
  node.right.left = None
  node.right.right = None

  return node

def findLCA(node, left, right):
  val = node.val
  if left < val and right > val: return val
  elif left > val: return findLCA(node.right, left, right)
  else: return findLCA(node.left, left, right)

import sys

for line in open(sys.argv[1], 'r'):
  line = map(int, line.rstrip('\n').split(' '))
  node = createTree()
  print findLCA(node, line[0], line[1])
