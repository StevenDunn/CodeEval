# seek for an intruder soln in py2 for codeeval by steven a dunn

import sys, re

DOT_DEC_REGEX = r"[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}"
DOT_HEX_REGEX = r"0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}"
DOT_OCT_REGEX = r"0[0-9]{1,3}\.0[0-9]{1,3}\.0[0-9]{1,3}\.0[0-9]{1,3}"
DOT_BIN_REGEX = r"[0-1]{8}\.[0-1]{8}\.[0-1]{8}\.[0-1]{8}"

BIN_REGEX = r"[0-1]{8}[0-1]{8}[0-1]{8}[0-1]{8}"
OCT_REGEX = r"0[0-9]{1,3}0[0-9]{1,3}0[0-9]{1,3}0[0-9]{1,3}"
HEX_REGEX = r"0x[0-9a-f]{1,2}0x[0-9a-f]{1,2}0x[0-9a-f]{1,2}0x[0-9a-f]{1,2}"
DEC_REGEX = r"[0-9]{1,3}[0-9]{1,3}[0-9]{1,3}[0-9]{1,3}"

ip_regexes = [DOT_DEC_REGEX, DOT_HEX_REGEX, DOT_OCT_REGEX, DOT_BIN_REGEX, BIN_REGEX, OCT_REGEX, HEX_REGEX, DEC_REGEX]

def parse(line):
    matches = []
    for regex in ip_regexes:
        m = re.findall(regex, line)
        for address in m:
            if validate(address, regex):
                matches.append(convert(address, regex))
    return matches

def convert(address, regex):
    print "address: ", address
    decimal = ""
    if '.' in address:
        address = address.split('.')
        octets = []
        for octet in address:
            octets.append(str(int(octet, 0)))
        decimal = "".join(octets)
    else:
        decimal = str(int(address))
    print "decimal conversion: ", decimal
    return decimal

def validate_dotted(address, base):
    address = address.split(".")
    if len(address) != 4:
        return False
    for octet in address:
        if int(octet, base) < 0 or int(octet, base) > 255:
            return False
    return True

def validate_non_dotted(address, base):
    if int(address, base) < 0 or int(address, base) > 4294967295:
        return False
    return True

def validate(address, regex):
    if regex == DOT_DEC_REGEX:
        return validate_dotted(address, 10)

    if regex == DOT_HEX_REGEX:
       return validate_dotted(address, 16)

    if regex == DOT_OCT_REGEX:
        return validate_dotted(address, 8)

    if regex == DOT_BIN_REGEX:
        return validate_dotted(address, 2)

    if regex == BIN_REGEX:
        return validate_non_dotted(address, 2)

    if regex == OCT_REGEX:
        return validate_non_dotted(address, 8)

    if regex == HEX_REGEX:
        return validate_non_dotted(address, 16)

    if regex == DEC_REGEX:
        return validate_non_dotted(address, 10)

address_list = []
f = open(sys.argv[1], 'r')
for line in f:
    addresses = parse(line.strip())
    address_list.append(addresses)
f.close()
print address_list
#print max(address_list, key=address_list.count)