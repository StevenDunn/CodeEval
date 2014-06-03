# bats challenge solution in ruby for codeeval by steven a dunn

def too_close(spot, bats, spacing)
    bats.each do |bat|
        if (spot - bat).abs < spacing then return true end
    end
    false
end

File.open(ARGV[0], 'r') do |file|
    while line = file.gets
        length, spacing, number_of_bats, *bats = line.split

        length = (length.to_i - 6) # 6cm spacing on either side
        spacing = spacing.to_i
        bats.map!{|x| x.to_i}.sort!

        total_new_bats = 0
        6.upto(length) do |spot|
            if !too_close(spot, bats, spacing)
                total_new_bats += 1
                bats << spot
            end
        end
        puts total_new_bats
    end
end