# sum of integers from file soln for codeeval.com by steven a dunn

sum = 0
File.open(ARGV[0], 'r').each_line do |line|
    sum += line.to_i
end
puts sum