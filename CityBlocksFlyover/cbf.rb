# city blocks flyover soln in ruby for codeeval by steven a dunn

File.open(ARGV[0], 'r') do |file|
    while line = file.gets
        x, y = line.split

        x = x[1..-2].split(",").map{|a| a.to_i}
        x.delete(0)

        y = y[1..-2].split(",").map{|a| a.to_i}
        y.delete(0)

        m = y[-1]/x[-1].to_f

        x_vals = Hash.new
        x.each do |val|
            x_vals[val] = m*val
        end

        y_vals = Hash.new
        y.each do |val|
            if !x_vals.has_value?(val)
                y_vals[val] = val/m
            end
        end

        total_squares = x_vals.length + y_vals.length
        puts total_squares
    end
end