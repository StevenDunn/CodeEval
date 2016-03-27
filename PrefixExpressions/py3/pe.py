# Prefix Expressions solution in py3 for CodeEval.com by Steven A. Dunn

import sys


def is_operator(opr):
  if opr == "+" or opr == "-" or opr == "*" or opr == "/":
    return True
  return False

def evaluate(opr, x, y):
  x, y = float(x), float(y)
  if opr == "+":
    return x + y
  if opr == "-":
    return x - y
  if opr == "*":
    return x * y
  if opr == "/":
    return x / y
  else:
    return 0;

def update_expression(expression, result, i):
  updated_expression = expression[0:i]
  updated_expression.append(result)
  for j in range(i+3, len(expression), 1):
    updated_expression += expression[j]
  return updated_expression

def calculate(expression):
  result = 0
  tokens = expression.strip().split()
  for i in range(len(tokens)-1, -1, -1):
    if is_operator(tokens[i]):
      result = evaluate(tokens[i], tokens[i+1], tokens[i+2])
      tokens = update_expression(tokens, result, i)
  return result

f = open(sys.argv[1], 'r')
for line in f:
  print (int(calculate(line)))
f.close()