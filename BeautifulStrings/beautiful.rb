#beautiful strings soln in rb for codeeval.com by steven a dunn

def getCounts(line)
    counts = Array.new(26, 0)
    ascii_zero = 97

    line.split("").each do |c|
        i = c.ord - ascii_zero
        idx = i.to_i
        if idx >= 0 and i < 26
            counts[idx] += 1
        end
    end
    counts
end

def getBeauty(counts)
    beauty = 0
    weight = 26

    counts.sort!()

    (counts.length - 1).downto(0) do |i|
        beauty += weight * counts[i]
        weight -= 1
    end
    beauty
end

File.open(ARGV[0], 'r').each_line do |line|
  line = line.chomp.downcase
  counts = getCounts(line)
  beauty = getBeauty(counts)
  puts beauty
end