# ip package soln in python2 for codeeval by steven dunn

import sys, struct

# code from Stack Overflow for the checksum b/c I'm not a networking guy
def carry_around_add(a, b):
    c = a + b
    return (c & 0xffff) + (c >> 16)

def get_checksum(msg):
    s = 0
    for i in range(0, len(msg), 2):
        w = ord(msg[i]) + (ord(msg[i+1]) << 8)
        s = carry_around_add(s, w)
    return ~s & 0xffff

def format_hex_address(bin_address):
    hex_address = []
    for i in range(0, 32, 8):
        a = str(hex(int(bin_address[i:i+4], 2)))[2:]
        b = str(hex(int(bin_address[i+4:i+8], 2)))[2:]
        hex_address.append(a + b)
    return " ".join(hex_address)

def parse_ipv4(address):
    bin_address = ""
    address = address.split('.')
    for section in address:
        bin_address += format(int(section), '08b')
    return format_hex_address(bin_address)

def parse(line):
    line = line.strip().split()
    source, destination = line[0], line[1]
    package = line[2:]
    
    hex_header = package[:20]

    return source, destination, hex_header

for line in open(sys.argv[1], 'r'):
    source, destination, octets = parse(line)

    source_ip = parse_ipv4(source)
    destination_ip = parse_ipv4(destination)    

    result = " ".join(octets[0:10]) + " "

    # zero out checksum bytes for calculation
    octets[10:12] = ["00", "00"]
    octets[12:16] = source_ip.split()
    octets[16:20] = destination_ip.split()

    checksum_data = map(lambda x: int(x, 16), octets)
    checksum_data = struct.pack("%dB" % len(checksum_data), *checksum_data)
    #checksum = hex(get_checksum(checksum_data))[2:]

    checksum = bin(get_checksum(checksum_data))[2:]
    checksum = hex(int(checksum[8:], 2))[2:] + " " + hex(int(checksum[0:8], 2))[2:]

    result += checksum + " "
    result += source_ip + " " + destination_ip

    print result