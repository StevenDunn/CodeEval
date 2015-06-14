# calculate distance soln in rb for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line.chomp!
    sep = line.index(") (")

    coord1 = line[1..sep].split(',').map(&:to_i)
    coord2 = line[sep+3..line.length-1].split(',').map(&:to_i)

    distance = Math.sqrt((coord2[0] - coord1[0]) ** 2 + (coord2[1] - coord1[1]) ** 2)
    puts distance.to_i
end