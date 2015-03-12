# racing chars py2 soln by steven a dunn for code eval

import sys

def update_direction(prev, index):
  direction = None
  if index < prev:
    direction = '/'
  elif index == prev:
    direction = '|'
  else:
    direction = "\\"

  return direction

f = open(sys.argv[1], 'r')
direction = '|'
prev = None
for line in f:
    output_line = list(line.strip());
    gate_index = line.index('_')
    if not prev:
        prev = gate_index
    checkpoint_index = line.find('C')
    if checkpoint_index == -1:
        direction = update_direction(prev, gate_index)
        output_line[gate_index] = direction
        prev = gate_index
    else:
      direction = update_direction(prev, checkpoint_index)
      output_line[checkpoint_index] = direction
      prev = checkpoint_index
    print "".join(output_line)
f.close();