# a pile of bricks soln by steven a dunn for code eval

import sys, math

def parse_hole_coordinates(hole_vertices):
    hole_vertices.gsub!(/[\[\],]/, ' ')
    hole_vertices = hole_vertices.split(" ").to_a
    hole_vertices.map! { |e| e.to_i }

    x = math.abs(hole_vertices[0] - hole_vertices[2])
    y = math.abs(hole_vertices[1] - hole_vertices[3])

    return x, y
end

f = open(sys.argv[1], 'r')
for line in f:
	hole_vertices, brick_vertices = line.strip().split("|")
	x, y = parse_hole_coordinates(hole_vertices)
	bricks = parse_brick_vertices(brick_vertices)
f.close()

"""


File.open(ARGV[0], 'r').each_line do |line|
    hole_vertices, brick_vertices = line.chomp.split("|")

    x, y = parse_hole_coordinates(hole_vertices)
    bricks = parse_brick_vertices(brick_vertices)

    result = []
    bricks.each do |brick_idx, brick_coords|
        if brick_fits(x, y, brick_coords)
            result << brick_idx
        end
    end

    if result.empty?
        puts "-"
    else
        puts result.sort!.join(",")
    end
end


def parse_hole_coordinates(hole_vertices)
    hole_vertices.gsub!(/[\[\],]/, ' ')
    hole_vertices = hole_vertices.split(" ").to_a
    hole_vertices.map! { |e| e.to_i }

    x = (hole_vertices[0] - hole_vertices[2]).abs
    y = (hole_vertices[1] - hole_vertices[3]).abs

    [x, y]
end

def parse_brick_vertices(brick_vertices)
    bricks = {}
    brick_list = brick_vertices.split(";")
    brick_list.each do |brick|
        brick.gsub!(/[\(\)]/, '')
        brick = brick.split(" ")
        brick_idx = brick[0].to_i
        brick_coord_1 = brick[1].gsub!(/[\[\]]/, '').split(",").map { |e| e.to_i }
        brick_coord_2 = brick[2].gsub!(/[\[\]]/, '').split(",").map { |e| e.to_i }

        bricks[brick_idx] = [(brick_coord_1[0] - brick_coord_2[0]).abs, (brick_coord_1[1] - brick_coord_2[1]).abs, (brick_coord_1[2] - brick_coord_2[2]).abs]
    end
    bricks
end

def brick_fits(x, y, brick_coords)
    brick_x = brick_coords[0]
    brick_y = brick_coords[1]
    brick_z = brick_coords[2]

    #puts "#{x} #{y} #{brick_coords}"

    if brick_x < 0 || brick_y < 0 || brick_z < 0
        return false
    end



    # test the 3 possible brick sides:
    # xy
    if brick_x <= x && brick_y <= y
        return true
    elsif brick_y <= x && brick_x <= y
        return true
    # xz
    elsif brick_x <= x && brick_z <= y
        return true
    elsif brick_z <= x && brick_x <= y
        return true
    # yz
    elsif brick_y <= x && brick_z <= y
        return true
    elsif brick_z <= x && brick_y <= y
        return true
    end
    false
end
"""