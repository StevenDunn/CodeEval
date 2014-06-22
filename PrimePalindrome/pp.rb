# prime palindrome solution in ruby for code eval by steven a dunn

def prime?(i)
  (2..i-1).each do |x|
    if i % x == 0 
      false
      break
    end
    true
  end
end

def palindrome?(i)
  if i.to_s.reverse == i.to_s
    true
  else
    false
  end
end

1000.downto(1).each do |i|
  if prime?(i) && palindrome?(i)
    puts i
    break
  end
end
