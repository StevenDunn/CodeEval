# longest word soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(' ')
    max_length = -1
    max_word = ""
    line.each do |word|
        if word.length > max_length
            max_length = word.length
            max_word = word
        end
    end
    puts max_word
end