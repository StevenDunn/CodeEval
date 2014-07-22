# multiply lists soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(" | ")
    line1 = line[0].split(' ').map(&:to_i)
    line2 = line[1].split(' ').map(&:to_i)

    line1.zip(line2).each do |x, y|
        print "#{x * y} "
    end
    puts
end