# Poker Hands soln in Py2 for CodeEval.com by Steven A. Dunn

def compare(left_rank, left_hand, right_rank, right_hand):
  if left_rank > right_rank:
    return "left"
  elif right_rank > left_rank:
    return "right"
  else:
    while left_hand or right_hand:
      left_high = highCard(left_hand)
      right_high = highCard(right_hand)

      if left_high > right_high:
        return "left"
      if right_high > left_high:
        return "right"
      left_hand[:] = [x for x in left_hand if x != max(left_hand)]
      right_hand[:] = [x for x in right_hand if x != max(right_hand)]
    return "none"

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

def getCounts(hand):
  vals = getVals(hand)
  counts = []
  for val in vals:
    counts.append(vals.count(val))
  return counts

def isFourOfAKind(hand):
 counts = getCounts(hand)
 for count in counts:
   if count == 4: return True
 return False

def isThreeOfAKind(hand):
  counts = getCounts(hand)
  for count in counts:
    if count == 3: return True
  return False

def isOnePair(hand):
  counts = getCounts(hand)
  pairCount = 0
  for count in counts:
    if count == 2:
      pairCount = pairCount + 1
  if pairCount == 2: return True
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

def isTwoPairs(hand):
  counts = getCounts(hand)
  pairCount = 0
  for count in counts:
    if count == 2:
      pairCount = pairCount + 1
  if pairCount == 4: return True
  return False

def highCard(hand):
  vals = getVals(hand)
  return max(vals)

def rank(numericHand):
  if isRoyalFlush(numericHand): return 23
  elif isStraightFlush(numericHand): return 22
  elif isFourOfAKind(numericHand): return 21
  elif isFullHouse(numericHand): return 20
  elif isFlush(numericHand): return 19
  elif isStraight(numericHand): return 18
  elif isThreeOfAKind(numericHand): return 17
  elif isTwoPairs(numericHand): return 16
  elif isOnePair(numericHand): return 15
  else: return highCard(numericHand)

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

import sys

for line in open(sys.argv[1], 'r'):

  line = line.rstrip('\n').split(' ')
  left = line[0:5]
  right = line[5:]

  left_hand = makeNumeric(left)
  right_hand = makeNumeric(right)

  left_rank = rank(left_hand)
  right_rank = rank(right_hand)

  print compare(left_rank, left_hand, right_rank, right_hand)
