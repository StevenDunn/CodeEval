# Gronsfeld cipher soln in py2 for code eval by steven a dunn

import sys

alphabet = [" ", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

def parse_cipher(ciphertext, cipher):
    while len(cipher) < len(ciphertext):
        cipher *= 2
    cipher = cipher[0:len(ciphertext)]
    return cipher

def decrypt(ciphertext, cipher):
    cipher = parse_cipher(ciphertext, cipher)
    text = ""
    for i in range(0, len(ciphertext)):
        location = alphabet.index(ciphertext[i])
        updated_location = location - int(cipher[i])
        text += alphabet[updated_location]
    return text

f = open(sys.argv[1], 'r')
for line in f:
    [cipher, ciphertext] = line.strip('\n').split(";")
    print decrypt(ciphertext, cipher)
f.close()