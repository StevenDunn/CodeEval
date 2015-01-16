# Roman numberumerals solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys

def calc(number, value, letter):
  while number >= value:
    sys.stdout.write(letter)
    number -= value
  return number


for line in open(sys.argv[1], 'r'):
  number = int(line)
  number = calc(number, 1000, "M")
  number = calc(number, 900, "CM")
  number = calc(number, 500, "D")
  number = calc(number, 400, "CD")
  number = calc(number, 100, "C")
  number = calc(number, 90, "XC")
  number = calc(number, 50, "L")
  number = calc(number, 40, "XL")
  number = calc(number, 10, "X")
  number = calc(number, 9, "IX")
  number = calc(number, 5, "V")
  number = calc(number, 4, "IV")
  for i in range(0, number):
    sys.stdout.write("I")
  print
