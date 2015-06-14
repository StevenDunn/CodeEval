# even numbers soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.to_i
    if line % 2 == 0
        puts 1
    else
        puts 0
    end
end