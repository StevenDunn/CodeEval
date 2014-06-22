# bit positions solution in ruby for code eval by steven a dunn

File.open(ARGV[0]).each_line do |line|
  n, p1, p2 = line.split(',').map { |x| x = x.to_i }
  n = n.to_s(2)
  
  if n[-p1] == n[-p2]
    puts "true"
  else
    puts "false"
  end
end
