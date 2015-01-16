# Prime Palindrome solution in Python 2 for CodeEval.com

import sys

def isPrime(n):
  if(n % 2 == 0):
    return False
  else:
    for i in range(3, n, 2):
      if(n % i == 0):
        return False
  return True

def isPalindrome(n):
  if(str(n) == str(n)[::-1]):
    return True
  return False

for palIdx in range(1000, 1, -1):
  if(isPrime(palIdx) and isPalindrome(palIdx)):
    print (palIdx)
    sys.exit()
