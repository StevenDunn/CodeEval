# capitalize words soln in rb for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split.map { |sym| sym[0].upcase + sym[1..-1] }
    puts line.join(" ")
end