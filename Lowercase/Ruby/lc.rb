# lowercase solution in ruby for code eval by steven a dunn

File.open(ARGV[0]).each_line do |line|
  puts line.downcase
end
