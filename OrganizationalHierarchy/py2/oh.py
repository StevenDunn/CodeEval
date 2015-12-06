# organizational hierarchy soln in py2 for code eval by steven a dunn

import sys

hierarchy = {}

def create_hierarchy(data):
  global hierarchy
  hierarchy = {}
  for entry in data:
    manager, employee = entry[0], entry[1]
    if manager in hierarchy.keys():
      hierarchy[manager].append(employee)
    else:
      hierarchy[manager] = [employee]
  for key, value in hierarchy.items():
    value.sort()
  
def format_hierarchy(start):
  global hierarchy
  sys.stdout.write(start + " [")

  for employee in hierarchy[start]:
    if employee in hierarchy.keys():
      format_hierarchy(employee)
    else:
      sys.stdout.write(employee)
    if employee != hierarchy[start][-1]:
      sys.stdout.write(", ")
  sys.stdout.write("]")

f = open(sys.argv[1], 'r')
for line in f:
  data = line.strip().split(" | ") 
  create_hierarchy(data)
  format_hierarchy('a')
  print
f.close()