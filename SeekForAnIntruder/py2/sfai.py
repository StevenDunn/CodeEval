# seek for an intruder soln in py2 for codeeval by steven a dunn

import sys, re, collections

DOT_DEC_REGEX = r"[1-9]{1}[0-9]{2,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}"
DOT_HEX_REGEX = r"0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}"
DOT_OCT_REGEX = r"0[0-7]{1,3}\.0[0-7]{1,3}\.0[0-7]{1,3}\.0[0-7]{1,3}"
DOT_BIN_REGEX = r"[0-1]{8}\.[0-1]{8}\.[0-1]{8}\.[0-1]{8}"

DEC_REGEX = r"([\d]+)"
HEX_REGEX = r"0x[0-9a-f]+"
OCT_REGEX = r"0[0-7]+"
BIN_REGEX = r"[0-1]+"

ip_regexes = [DOT_DEC_REGEX, DOT_HEX_REGEX, DOT_OCT_REGEX, DOT_BIN_REGEX, DEC_REGEX, HEX_REGEX, OCT_REGEX, BIN_REGEX]

def create_decimal_ip(octets):
    decimals = [octets[0] * (256 * 256 * 256), octets[1] * (256 * 256), octets[2] * (256), octets[3]]
    return decimals[0] + decimals[1] + decimals[2] + decimals[3]

def get_base(regex):
    if regex == DOT_DEC_REGEX or regex == DEC_REGEX:
        return 10
    if regex == DOT_HEX_REGEX or regex == HEX_REGEX:
        return 16
    if regex == DOT_OCT_REGEX or regex == OCT_REGEX:
        return 8
    if regex == DOT_BIN_REGEX or regex == BIN_REGEX:
        return 2
    return 0

def convert(address, regex):
    decimal = ""
    if '.' in address:
        address = address.split('.')
        octets = []
        for octet in address:
            octets.append(int(octet, get_base(regex)))
        decimal = create_decimal_ip(octets)
    else:
        decimal = int(address, get_base(regex))
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

def parse(line):
    matches = []
    for regex in ip_regexes:
        m = re.findall(regex, line)
        for address in m:
            if validate(address, regex):
                matches.append(convert(address, regex))
    return matches

def convert_to_ip(decimal):
    return str((decimal >> 24) & 0xFF) + "." + str((decimal >> 16) & 0xFF) + "." + str((decimal >> 8) & 0xFF) + "." + str(decimal & 0xFF)

address_list = []
f = open(sys.argv[1], 'r')
for line in f:
    addresses = parse(line.rstrip())
    address_list.append(addresses)
f.close()
address_list = [item for sublist in address_list for item in sublist]
address_list = [i for i in address_list if i >= (256*256*256)]
#address_list = collections.Counter(address_list)
#print address_list
print convert_to_ip(max(address_list, key=address_list.count))