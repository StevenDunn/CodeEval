
ZERO_REGEX = "A+"
ONE_REGEX = "(A+|B+)"

File.open(ARGV[0], 'r').each_line do |line|
    binary, text = line.chomp.split
    text_regex = []
    binary.split("").each do |digit|
        digit == "0" ? text_regex << ZERO_REGEX : text_regex << ONE_REGEX
    end
    regex = Regexp.new(text_regex.join)
    result = text =~ regex ? "Yes" : "No"
    puts result
end


=begin
File.open(ARGV[0], 'r').each_line do |line|
    binary, text = line.chomp.split(" ")

    text = text.squeeze('A-B')

    perms = []

    binary.split("").each do |digit|
        if digit == "1"
            if perms.empty?
                perms << "A"
                perms << "B"
            else
                perms_a = perms.map{ |x| x += "A" }
                perms_b = perms.map{ |x| x += "B" }
                perms = perms_a.concat(perms_b)
                perms.map! { |x| x.squeeze('A-B') }
            end
        else
            if perms.empty?
                perms << "A"
            end
            perms.map!{ |x| x += "A" }
            perms.map! { |x| x.squeeze('A-B') }
        end

        perms.each do |perm|
            if perm != text[0...perm.length]
                perms.delete(perm)
            end
        end
    end

    if perms.include? text
        puts "Yes"
    else
        puts "No"
    end
end
=end