# find a writer soln in rb for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp

    if line.empty?
        next
    end

    line = line.split('|')
    name = line[0]
    key = line[1].chomp.split(' ').map(&:to_i)

    key.each do |k|
       print name[k - 1]
    end
    puts
end