# a pile of bricks soln in rb for codeeval by steven a dunn

class Brick
    attr_accessor :index, :x, :y, :z

    def initialize(params)
        @index = params[0]
        @x = params[1]
        @y = params[2]
        @z = params[3]
    end

    def fits(hole)
        false
    end
end

def parse_brick_data(line)
    line.gsub!(/[\(\)]/, "")
    line = line.split

    index = line[0]
    coord1 = line[1].gsub(/[\]\[]/, "").split(",").map(&:to_i)
    coord2 = line[2].gsub(/[\]\[]/, "").split(",").map(&:to_i)

    x = (coord1[0] - coord2[0]).abs
    y = (coord1[1] - coord2[1]).abs
    z = (coord1[2] - coord2[2]).abs

    [index, x, y, z]
end

File.open(ARGV[0], 'r').each_line do |line|
    line = line.split("|")

    hole_coordinates = line[0]
    brick_data = line[1]

    hole_coordinates = hole_coordinates.gsub(/[\[\]]/, "").split
    hole_coordinates.map!{|sym| sym.split(",")}
    hole_coordinates = hole_coordinates.map{|sym| sym.map(&:to_i)}

    brick_data = brick_data.chomp.split(";")

    bricks = Array.new
    brick_data.each do |brick|
        bricks << Brick.new(parse_brick_data(brick))
    end

    results = ["test data"]
    bricks.each do |brick|
        if (brick.fits(hole_coordinates))
            results << brick.index
        end
    end

    puts results.join(",")
    puts
end