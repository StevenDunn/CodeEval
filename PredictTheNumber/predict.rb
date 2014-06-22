# predict the number solution in ruby for code eval by steven a dunn

$seq = [0, 1]

def update(n)
  if n == 0
    1
  elsif n == 1
    2
  elsif n == 2
    0
  end
end

def calculate_seq(x)
  puts x
  while $seq.length < x
    updated_seq = []
    $seq.each do |entry|
      updated_seq << update(entry)
    end 
    $seq << updated_seq
  end
end

File.open(ARGV[0]).each_line do |line|
  n = line.to_i
  x = 2 ** 0
  while x < n
    x *= 2
  end
  x /= 2
  diff = n - x
  
  if $seq.length < x
    calculate_seq x
  end 
  
  if n == 0
    puts 0
  else
    puts update($seq[diff])
  end
end
