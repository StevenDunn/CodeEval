# predict the number solution in ruby for code eval by steven a dunn

$seq = [0, 1]

def calculate_x(n)
  x = 2
  while x <= n
    x *= 2
  end
  x/2
end

File.open(ARGV[0]).each_line do |line|

  n = line.to_i
  #puts "n: #{n}"

  x = calculate_x(n)
  #puts "initial x: #{x}"
  offset = 0
  while n > 0
    n -= x
    #puts "updated n: #{n}"
    offset += 1
    x = calculate_x(n)
    #puts "updated x: #{x}"
  end
  #puts n
  #puts offset % 3
  #puts "final: #{offset % 3}"
  puts offset % 3
end
