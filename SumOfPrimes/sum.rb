# sum of primes soln in ruby for code eval by steven a dunn

def prime?(i)
  if i % 2 == 0 then return false end

  (3..i-1).step(2).each do |x|
    if i % x == 0 then return false end
  end
  true
end

# start at 2 
num = 3
sum = 2
count = 1
while count < 1000
  if prime?(num) 
    sum += num 
    count += 1
  end
  num += 2
end

puts sum
