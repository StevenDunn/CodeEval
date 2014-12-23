# lettercase percentage ratio soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line.chomp!

    upper_count = 0.0
    lower_count = 0.0
    chars = line.split("").map do |x|
        if x =~ /[A-Z]/
            upper_count += 1
        else
            lower_count += 1
        end
    end

    total_count = upper_count + lower_count
    upper_percent = (upper_count / total_count) * 100
    lower_percent = (lower_count / total_count) * 100

    printf("lowercase: %.2f uppercase %.2f \n", lower_percent, upper_percent)
end
