# fizz buzz solution in ruby for code eval by steven a dunn

File.open(ARGV[0]).each_line do |line|
  a, b, n = line.split.map! {|x| x = x.to_i }
  (1..n).each do |i|
    result = ""
    if i % a == 0
      result += "F"
    end
    if i % b == 0
      result += "B"
    end
    if result.empty?
      print "#{i} "
    else
      print "#{result} "
    end
  end
  puts
end
