# compressed sequence soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(' ')
    count = 0
    char = line[0]
    line.each do |i|
        if i == char
            count += 1
        else
            print "#{count} #{char} "
            count = 1
            char = i
        end
    end
    print "#{count} #{char} "
    puts
end
