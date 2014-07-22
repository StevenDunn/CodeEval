# road trip soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(";")
    distances = []
    line.each do |entry|
        distances << entry.split(",")[1]
    end
    distances.map!(&:to_i).sort!
    results = []
    cur_pos = 0
    distances.each do |distance|
        location = distance - cur_pos
        results << location
        cur_pos = distance
    end
    puts results.join(",")
end