# N mod M soln in rb for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(',')
    n = line[0].to_i
    m = line[1].to_i

    x = n / m
    y = x * m
    mod = n - y

    puts mod
end