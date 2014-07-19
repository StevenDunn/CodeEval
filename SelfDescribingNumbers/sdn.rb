# self describing numbers soln in rb for codeeval.com by steven a dunn

def isSelfDescribing(n)
    counts = Array.new(10, 0)

    n.split("").each do |c|
        counts[c.to_i] += 1
    end

    (0..n.length).each do |i|
        c = n[i].to_i
        unless c == counts[i]
            return false
        end
    end

    return true;
end

File.open(ARGV[0], 'r').each_line do |line|
    if isSelfDescribing(line.chomp)
        puts 1
    else
        puts 0
    end
end