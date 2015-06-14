# rightmost char soln in rb for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    params = line.chomp.split(',')
    idx = params[0].rindex(params[1])
    if idx.nil?
        puts -1
    else
        puts idx
    end
end