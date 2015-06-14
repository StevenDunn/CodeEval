# multiples of a number solution in ruby for code eval by steven a dunn

File.open(ARGV[0]).each_line do |line|
  x, n = line.split(',').map {|x| x = x.to_i }
  
  multiplier = 2
  while true
    multiple = n * multiplier
    if multiple >= x
      puts multiple
      break
    end
    multiplier += 1
  end
end
