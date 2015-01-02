# suggest groups soln in py for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

interests = {}
friends = {}

for line in f:
    line = line.split(":")
    user = line[0]

    user_friends = line[1].split(",")
    friends[user] = user_friends

    user_interests = line[2].strip().split(",")
    interests[user] = user_interests

f.seek(0)
for line in f:
    potential_interests = []
    user = line.split(":")[0]

    friend_interests = {}
    for friend in friends[user]:
        for specific_interest in interests[friend]:
            if specific_interest == '':
                continue
            if specific_interest in friend_interests:
                friend_interests[specific_interest] += 1
            else:
                friend_interests[specific_interest] = 1

    for specific_interest, count in friend_interests.items():
        if specific_interest not in interests[user]:
            if float(count)/len(friends[user]) * 100 >= 50:
                potential_interests.append(specific_interest)

    if len(potential_interests) > 0:
        potential_interests = sorted(potential_interests)
        print user + ":" + ",".join(potential_interests)
f.close()