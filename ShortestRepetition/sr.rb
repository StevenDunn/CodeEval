# shortest repetition soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line.chomp!
    period = 1
    subSeq = line[0]
    (1...line.length).each do |i|
        if line[period..-1].index(subSeq) != 0
            period += 1
            subSeq += line[i]
        end
    end
    puts period
end