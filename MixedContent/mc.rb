# mixed content soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(',')
    digits = []
    words = []
    line.each do |entry|
        if entry =~ /\A[-+]?[0-9]*\.?[0-9]+\Z/
            digits << entry
        else
            words << entry
        end
    end
    if words.empty?
        puts "#{digits.join(",")}"
    elsif digits.empty?
        puts "#{words.join(",")}"
    else
        puts "#{words.join(",")}|#{digits.join(",")}"
    end
end