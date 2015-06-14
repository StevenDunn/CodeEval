#happy numbers soln in rb for codeeval.com by steven a dunn

def isHappy(n, visited)
    sum = 0
    n.split("").each do |c|
        sum += c.to_i * c.to_i
    end

    if sum == 1
        return true
    end

    if visited.include? sum
        return false;
    end

    visited << sum

    if isHappy(sum.to_s, visited)
        return true;
    end

    return false;
end


File.open(ARGV[0], 'r').each_line do |line|
    visited = []
    if isHappy(line.chomp, visited)
        puts 1
    else
        puts 0
    end
end