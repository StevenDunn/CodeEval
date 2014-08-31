# interrupted bubble sort rb solution for codeeval by steven a dunn

def bubble_sort(vals, steps)
    n = 0
    while n < steps
        vals.each_with_index do |val, index|
            if index >= vals.length - 1 - n then next end
            next_val = vals[index+1]
            if next_val < val
                vals[index+1] = val
                vals[index] = next_val
            end
        end
        n += 1
    end

    return vals
end

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(" | ")
    vals = line[0].split.map { |x| x.to_i }
    steps = line[1].to_i

    vals = bubble_sort(vals, steps)

    puts "#{vals.join(" ")}"
end