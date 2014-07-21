# lowest unique number soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    nums = line.chomp.split(' ')
    lowest = 10
    nums.each do |i|
        if nums.count(i) == 1 and i.to_i < lowest
            lowest = i.to_i
        end
    end
    if lowest == 10
        puts 0
    else
        puts nums.index(lowest.to_s) + 1
    end
end