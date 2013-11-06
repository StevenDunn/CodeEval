# Cash Register solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

coins = [
  ("ONE HUNDRED", 10000),
  ("FIFTY", 5000),
  ("TWENTY", 2000),
  ("TEN", 1000),
  ("FIVE", 500),
  ("TWO", 200),
  ("ONE", 100),
  ("HALF DOLLAR", 50),
  ("QUARTER", 25),
  ("DIME", 10),
  ("NICKEL", 5),
  ("PENNY", 1)
]

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(';')
  purchase_price = int(float(line[0]) * 100)
  cash = int(float(line[1]) * 100)
  diff = cash - purchase_price
  if diff < 0:
    print "ERROR"
    continue
  elif diff == 0:
    print "ZERO"
    continue
  else:
    change = []
    for coin in coins:
      while diff >= coin[1]:
        diff -= coin[1]
        change.append(coin[0])
    for i in range(0, len(change)-1):
      sys.stdout.write(str(change[i]) + ",")
    print change[-1]

