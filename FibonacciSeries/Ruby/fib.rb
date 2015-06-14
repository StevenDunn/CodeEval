# fib series solution in ruby for code eval by steven a dunn

def fib(n)
  if n == 0 then return 0 end
  if n == 1 then return 1 end

  f1 = 0
  f2 = 1

  2.upto(n) do 
    tmp = f2
    f2 += f1
    f1 = tmp
  end

  return f2
end

File.open(ARGV[0]).each_line do |line|
  n = line.to_i
  puts fib(n)
end
