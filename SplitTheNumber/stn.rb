# split the number solution in ruby for code eval by steven a dunn

File.open(ARGV[0]).each_line do |line|
  numbers, equation = line.split

  idx = equation.index('+')
  if idx.nil? then idx = equation.index('-') end 

  n1 = numbers.slice(0...idx).to_i 
  n2 = numbers.slice(idx..-1).to_i

  op = equation[idx] 

  if op == '+'
    puts n1 + n2
  else
    puts n1 - n2
  end
end
