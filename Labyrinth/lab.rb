#labyrinth soln in rb for codeeval by steven a dunn

dim_x = 0
dim_y = 0

path_coords = []
maze = []
start = nil
finish = nil

line_count = 0
File.open(ARGV[0], 'r').each_line do |line|
    maze << line.chomp.split("").to_a
    line.chomp.split("").each_with_index do |char, index|
        if char == " "
            path_coords << [index, line_count]

            if line_count == 0 || index == 0 || index == maze[0].length-1
                if start.nil?
                    start = [index, line_count]
                else
                    finish = [index, line_count]
                end
            end
        end
    end
    dim_x = line.length - 1
    line_count += 1
end

dim_y = line_count - 1

if finish.nil?
    finish = [maze[dim_x].index(" "), dim_y]
end

solution_path = []
visited = []

maze[start[1]][start[0]] = "+"
maze[finish[1]][finish[0]] = "+"

current = start
neighbors = find_neighbors(current)




maze.each do |line|
    line.each do |cell|
        print cell
    end
    puts
end

=begin
path_idx = 0
(0..dim_y).each do |y|
    (0..dim_x).each do |x|
        if path_coords[path_idx] == [x,y]
            #if path_coords[path_idx] == start
            #    print "S"
            #elsif path_coords[path_idx] == finish
            #    print "F"
            #else
                print " "
            #end
            path_idx += 1
        else
            print "*"
        end
    end
    puts
end
=end
