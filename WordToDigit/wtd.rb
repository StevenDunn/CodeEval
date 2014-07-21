# word to digit soln in rb for codeeval by steven a dunn

def convert(word)
    case word
    when "one" then 1
    when "two" then 2
    when "three" then 3
    when "four" then 4
    when "five" then 5
    when "six" then 6
    when "seven" then 7
    when "eight" then 8
    when "nine" then 9
    when "zero" then 0
    end
end

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(';')
    line.each do |word|
        print convert(word)
    end
    puts
end