# ip package soln in python2 for codeeval by steven dunn

import sys

for line in open(sys.argv[1], 'r'):
    line = line.strip().split()
    source = line[0]
    destination = line[1]
    package = line[2:-1]

    print source, destination
    
    i = 0
    version_ihl = package[i]

    i += 1
    dscp_ecn = package[i]

    i += 1
    total_length = package[i:i+1]

    i += 2
    identification = package[i:i+1]

    i += 2
    flags_frag_offset = package[i:i+1]

    i += 2
    time_to_live = package[i]

    i += 1
    protocol = package[i]

    i += 1
    header_checksum = package[i:i+1]

    i += 2
    source_ip_address = package[i:i+3]

    i += 4
    destination_ip_address = package[i:i+3]

    i += 4
    ihl = 0 #temp
    if ihl > 5:
    	options = package[i:i+3]
    	i += 4

