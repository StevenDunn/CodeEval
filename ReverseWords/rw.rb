# reverse words solution in ruby for code eval by steven a dunn

File.open(ARGV[0]).each_line do |line|
  words = line.split
  words.reverse.each { |word| print "#{word} " }
  puts
end
