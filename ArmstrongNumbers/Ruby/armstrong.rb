# armstrong numbers soln in rb for codeeval.com by steven a dunn

def isArmstrong(n)
    sum = 0
    numDigits = n.length

    n.split("").each do |c|
        sum += (c.to_i ** numDigits)
    end
    if sum == n.to_i
        return true
    end
    return false
end

File.open(ARGV[0], 'r').each_line do |line|
    if isArmstrong(line.chomp)
        puts "True"
    else
        puts "False"
    end
end