# sum of digits solution in ruby for code eval by steven a dunn

File.open(ARGV[0]).each_line do |line|
  n = line.to_s.scan(/./)

  sum = 0
  n.each { |c| sum += c.to_i }

  puts sum
end
