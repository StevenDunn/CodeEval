# json ids soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    ids = line.chomp.split("id")
    if ids.nil? || ids.empty?
        next
    end
    sum = 0
    ids.each do |i|
        labels = i.split("label")
        labels.each do |j|
            start = j.index("Label")
            if start.nil?
                start = 0
            end
            start += 6
            j = j[start..-1]
            finish = j.index("\"")
            if finish.nil?
                next
            end
            j = j[0..finish]
            j = j.to_i
            sum += j
        end
    end
    puts sum
end