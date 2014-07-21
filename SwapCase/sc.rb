# swapcase soln in rb for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    puts line.chomp.swapcase
end