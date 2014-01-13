# Poker Hands soln in Py2 for CodeEval.com by Steven A. Dunn

def isSameSuit(hand):
  suits = ""
  for card in hand:
    suits += card[1]
  suits = "".join(set(suits))
  if len(suits) == 1: return True
  return False

def getVals(hand):
  vals = []
  for card in hand:
    vals.append(card[0])
  map(int, vals)
  vals.sort()
  return vals

def isRoyalFlush(hand):
  if isSameSuit(hand):
    vals = getVals(hand)
    if vals == [10, 11, 12, 13, 14]: return True
  return False

def areConsecutiveVals(vals):
  val = vals[0]
  for i in range(1, len(vals)):
    if vals[i] - 1 != val:
      return False
    val = vals[i]
  return True
    
def isStraightFlush(hand):
  if isSameSuit(hand):
    vals = getVals(hand)
    if areConsecutiveVals(vals): 
      high_card = max(vals)
      return True
  return False;
   
def convert(val):
  if val == "T": return 10
  elif val == "J": return 11
  elif val == "Q": return 12
  elif val == "K": return 13
  elif val == "A": return 14
  else: return int(val)

def makeNumeric(hand):
  numericHand = []
  for card in hand:
    val = convert(card[0])
    suit = card[1]
    numericHand.append((val, suit))
  return numericHand

def isFourOfAKind(hand):
 counts = getCounts(hand)  
 for count in counts:
   if count == 4: return True
 return False

def isFullHouse(hand):
  if isThreeOfAKind(hand) and isOnePair(hand): 
    return True
  return False

def isFlush(hand):
  if isSameSuit(hand): return True
  return False

def isStraight(hand):
  if areConsecutiveVals(getVals(hand)): return True
  return False

def isThreeOfAKind(hand):
  counts = getCounts(hand)
  for count in counts:
    if count == 3: return True
  return False

def isTwoPairs(hand):
  counts = getCounts(hand)
  pairCount = 0
  for count in counts:
    if count == 2:
      pairCount = pairCount + 1
  if pairCount == 4: return True
  return False

def isOnePair(hand):
  counts = getCounts(hand)
  pairCount = 0
  for count in counts:
    if count == 2:
      pairCount = pairCount + 1
  if pairCount == 2: return True
  return False

def getCounts(hand):
  vals = getVals(hand)
  counts = []
  for val in vals:
    counts.append(vals.count(val))
  return counts

def highCard(hand):
  vals = getVals(hand)
  return max(vals)

def rank(hand):
  numericHand = makeNumeric(hand)
  if isRoyalFlush(numericHand): return (23, 23)
  elif isStraightFlush(numericHand): return (22, highCard(numericHand))
  elif isFourOfAKind(numericHand): return (21, highCard(numericHand))
  elif isFullHouse(numericHand): return (20, highCard(numericHand))
  elif isFlush(numericHand): return (19, highCard(numericHand))
  elif isStraight(numericHand): return (18, highCard(numericHand))
  elif isThreeOfAKind(numericHand): return (17, highCard(numericHand))
  elif isTwoPairs(numericHand): return (16, highCard(numericHand))
  elif isOnePair(numericHand): return (15, highCard(numericHand))
  else: return (highCard(numericHand), highCard(numericHand))

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(' ')
  left = line[0:5]
  right = line[5:]

  left_rank = rank(left)
  right_rank = rank(right)

  #print left, right
  #print left_rank, right_rank

  if left_rank[0] > right_rank[0]:
    print "left"
  elif right_rank[0] > left_rank[0]:
    print "right"
  else:
    if left_rank[1] > right_rank[1]:
      print "left"
    elif right_rank[1] > left_rank[1]:
      print "right"
    else: print "none"

