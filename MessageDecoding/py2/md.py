# message decoding solution in py 2 for code eval by steven a dunn

import sys

def get_header(line):
	idx = min(line.find('0'), line.find('1'))
	return line[0:idx], idx

def generate_key(key, key_len):
	binary = bin(int(key, 2)+1)[2:]
	while len(binary) < key_len:
		binary = "0" + binary
	return binary

def next_key(key, i, n):
	key_len = len(key)
	if i < (2 ** n) - 1:
		return [generate_key(key, key_len), i + 1, n]
	else:
		return ["0" * (key_len+1), 1, n + 1]

def create_header_dict(header_str):
	header = {}
	key = "0"
	i = 1
	n = 1
	for c in header_str:
		header[key] = c
		key, i, n = next_key(key, i, n)
	return header

def parse_message(header, message):
	result = ""
	while message:
		length = int(message[0:3], 2)
		message = message[3:]
		terminator = "1" * length
		if length == 0:
			break
		for idx in range(0, len(message), length):
			word = message[idx:idx+length]
			#print word
			if word == terminator:
				message = message[idx+length:]
				break
			else:
				result += header[word]
	return result

f = open(sys.argv[1], 'r')

for line in f:
	header_str, idx = get_header(line)
	header = create_header_dict(header_str)
	message = line[idx:]
	print parse_message(header, message)

f.close()