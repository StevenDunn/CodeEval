# roman and arabic soln in rb for codeeval by steven a dunn

def roman_to_arabic(num)
    case num
    when "I" then 1
    when "V" then 5
    when "X" then 10
    when "L" then 50
    when "C" then 100
    when "D" then 500
    when "M" then 1000
    end
end

def convert(pair)
    a = pair[0]
    r = pair[1]

    a = a.to_i
    r = roman_to_arabic(r)

    a * r
end

def greater(x, y)
    x = roman_to_arabic x
    y = roman_to_arabic y

    x > y
end

def calculate(digits, pairs)
    total = 0
    prev_r = pairs[0][-1]
    digits.each_with_index do |digit, index|

        if index == digits.length - 1
            total += digits[index]
            next
        end

        curr_r = pairs[index][-1]
        next_r = pairs[index+1][-1]

        if greater(next_r, curr_r)
            total -= digits[index]
        else
            total += digits[index]
        end
    end
    total
end

File.open(ARGV[0], 'r').each_line do |line|
    pairs = line.chomp.scan(/.{2}/)
    digits = pairs.map { |pair| convert(pair) }
    puts calculate(digits, pairs)
end