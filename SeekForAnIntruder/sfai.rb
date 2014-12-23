# seek for an intruder soln in rb for codeeval by steven a dunn

$ips = {}

def validate(entry)
    if entry <= 4294902526 && entry >= 0
        true
    else
        false
    end
end

def get_base(octet)
    # hex
    if octet[0..1] == "0x"
        base = 16
    # binary
    elsif octet =~ /^[01]{8,}/
        base = 2
    # octal
    elsif octet[0] == "0"
        base = 8
    # decimal
    else
        base = 10
    end
    base
end

def compute_ip_num(octets, base)
    octets.map!{ |x| x.to_i(base) }
    # 256**3, 256**2, 256**1, 256**0
    ip_num = octets[0] * 16777216 + octets[1] * 65536 + octets[2] * 256 + octets[3]
end

def convert(octets)
    base = get_base(octets[0])
    #puts "base: #{base}"
    if octets.length == 4
        compute_ip_num(octets, base)
    elsif octets.length == 1
        octets[0].to_i(base)
    else
        nil
    end
end

def add(ip)
    if $ips.has_key? ip
        $ips[ip] += 1
    else
        $ips[ip] = 1
    end
end

def extract_addresses(line)
    puts line
    octets = line.split('.')
    ip = convert(octets)
    if ip && validate(ip)
        add(ip)
    end
end

DOT_DEC_REGEX = /[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}/
DOT_HEX_REGEX = /0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}\.0x[0-9a-f]{1,2}/
DOT_OCT_REGEX = /0[0-9]{1,3}\.0[0-9]{1,3}\.0[0-9]{1,3}\.0[0-9]{1,3}/
DOT_BIN_REGEX = /[0-1]{8}\.[0-1]{8}\.[0-1]{8}\.[0-1]{8}/

BIN_REGEX = /[0-1]{8}[0-1]{8}[0-1]{8}[0-1]{8}/
OCT_REGEX = /0[0-9]{1,3}0[0-9]{1,3}0[0-9]{1,3}0[0-9]{1,3}/
HEX_REGEX = /0x[0-9a-f]{1,2}0x[0-9a-f]{1,2}0x[0-9a-f]{1,2}0x[0-9a-f]{1,2}/
DEC_REGEX = /[0-9]{1,3}[0-9]{1,3}[0-9]{1,3}[0-9]{1,3}/

def parse_line(line)
    # dotted decimal
    if line =~ DOT_DEC_REGEX
        extract_addresses(line.scan(DOT_DEC_REGEX).first)
    end

    # dotted hex
    if line =~ DOT_HEX_REGEX
        extract_addresses(line.scan(DOT_HEX_REGEX).first)
    end

    # dotted octal
    if line =~ DOT_OCT_REGEX
        extract_addresses(line.scan(DOT_OCT_REGEX).first)
    end

    # dotted binary
    if line =~ DOT_BIN_REGEX
        extract_addresses(line.scan(DOT_BIN_REGEX).first)
    end

    # binary
    if line =~ BIN_REGEX
        extract_addresses(line.scan(BIN_REGEX).first)
    end

    # octal
    if line =~ OCT_REGEX
        extract_addresses(line.scan(OCT_REGEX).first)
    end

    # hex
    if line =~ HEX_REGEX
        extract_addresses(line.scan(HEX_REGEX).first)
    end

    # decimal
    if line =~ DEC_REGEX
        extract_addresses(line.scan(DEC_REGEX).first)
    end
end

File.open(ARGV[0], 'r').each_line do |line|
    parse_line(line.chomp)
end
puts "#{$ips}"