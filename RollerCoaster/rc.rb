# roller coaster soln in rb for codeeval by steven a dunn

def is_letter(char)
    if char =~ /[[:alpha:]]/
        true
    else
        false
    end
end

File.open(ARGV[0], 'r').each_line do |line|
    letter_case = true
    line.chomp.split("").each do |char|
        if is_letter(char)
            if letter_case
                print char.upcase
            else
                print char.downcase
            end
            letter_case = !letter_case
        else
            print char
        end
    end
    puts
end