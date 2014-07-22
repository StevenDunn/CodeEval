# hidden digits soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line.chomp!
    result = ""
    line.split("").each do |char|
        ord = char.ord
        if (ord >= 48 && ord <= 57)
            result << (ord - 48).to_s
        elsif (ord >= 97 && ord <= 106)
            result << (ord - 97).to_s
        end
    end
    if result.empty?
        puts "NONE"
    else
        puts result
    end
end