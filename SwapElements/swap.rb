# swap elements soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(" : ")
    numbers = line[0].split(' ')
    swaps = line[1].split(", ")

    swaps.each do |swap|
        swap = swap.split('-')
        tmp = numbers[swap[0].to_i]
        numbers[swap[0].to_i] = numbers[swap[1].to_i]
        numbers[swap[1].to_i] = tmp
    end
    puts numbers.join(" ")
end