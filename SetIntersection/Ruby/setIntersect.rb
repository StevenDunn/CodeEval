# set intersection soln in rb for codeeval.com by steven a dunn

require 'set'

File.open(ARGV[0], 'r').each_line do |line|
    params = line.split(";")

    set1 = params[0].chomp.split(',').to_set
    set2 = params[1].chomp.split(',').to_set

    intersection = set1 & set2

    puts intersection.to_a.join(",")
end