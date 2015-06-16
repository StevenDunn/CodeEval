# data recovery solution in ruby for code eval by steven a dunn

input_file = ARGV[0]

File.open(input_file, 'r') do |file|
  while line = file.gets
    line = line.split(';')
    text = line[0].split
    indices = line[1].split.map!(&:to_i)

    missing_index = 0
    sorted_indices = indices.sort
    sorted_indices.each do |index|
      if index != missing_index + 1
        break
      end
      missing_index += 1
    end
    missing_index += 1

    mapping = text.zip(indices)
    mapping.each do |map| 
      if map[1].nil?
        map[1] = missing_index
      end
    end

    mapping.each do |map|
      map[0], map[1] = map[1], map[0]
    end
    mapping.sort!

    mapping.each do |map|
      print "#{map[1]} "
    end
    puts
  end
end
