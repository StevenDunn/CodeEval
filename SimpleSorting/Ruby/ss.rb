# simple sorting soln in rb for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
  line = line.chomp.split(' ').map {|sym| sym.to_f }
  line.sort!
  line.each do |elem|
    printf("%.3f ", elem)
  end
  puts
end