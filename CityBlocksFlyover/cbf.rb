# city blocks flyover soln in ruby for codeeval by steven a dunn

File.open(ARGV[0], 'r') do |file|
    while line = file.gets
        x, y = line.split

        x = x[1..-2].split(",").map{|a| a.to_i}
        xs = x.zip(x[1..-1])[0..-2]

        y = y[1..-2].split(",").map{|a| a.to_i}
        ys = y.zip(y[1..-1])[0..-2]

        m = y[-1]/x[-1].to_f

        total = 0
        xs.each do |x|
            ys.each do |y|
                if ( !(m * x[0] >= y[1] || m * x[1] <= y[0]) )
                    total += 1
                end
            end
        end
        puts total
    end
end