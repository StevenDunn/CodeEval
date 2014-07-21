# roman numerals soln in rb for codeeval by steven a dunn

def calc(number, value, letter)
    while number >= value
        print letter
        number -= value
    end
    number
end

File.open(ARGV[0], 'r').each_line do |line|
    number = line.to_i
    number = calc(number, 1000, "M")
    number = calc(number, 900, "CM")
    number = calc(number, 500, "D")
    number = calc(number, 400, "CD")
    number = calc(number, 100, "C")
    number = calc(number, 90, "XC")
    number = calc(number, 50, "L")
    number = calc(number, 40, "XL")
    number = calc(number, 10, "X")
    number = calc(number, 9, "IX")
    number = calc(number, 5, "V")
    number = calc(number, 4, "IV")
    (0...number).each do
        print "I"
    end
    puts
end