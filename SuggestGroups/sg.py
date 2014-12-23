# suggest groups soln in py for codeeval by steven a dunn

import sys

def add_user(user, interests = None):
    #if user not in users:
    users[user] = interests

f = open(sys.argv[1], 'r')

users = {}

# initial pass to populate data structure
for line in f:
    print line,
    line = line.split(":")
    user = line[0]
    print user,
    interests = line[2].strip().split(",")
    print interests
    add_user(user, interests)

    #friends = line[1].split(",")
    #for friend in friends:
    #    add_user(friend)

f.seek(0)
for line in f:
    print line


print users

f.close()