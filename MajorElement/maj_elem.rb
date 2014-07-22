# the major element soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    entries = line.chomp.split(',').map(&:to_i)
    l = entries.length
    counts = {}

    entries.each do |entry|
        if counts.include? entry
            counts[entry] = counts[entry] + 1
        else
            counts[entry] = 1
        end
    end

    result = -1
    counts.each do |key, value|
        if value > l/2
            result = key
            break
        end
    end

    if result != -1
        puts result
    else
        puts "None"
    end
end