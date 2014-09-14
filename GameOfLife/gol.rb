# game of life soln in rb for codeeval by steven a dunn

def get_neighbors(row, col, board)
    neighbors = []
    (row - 1).upto(row + 1) do |i|
        (col - 1).upto(col + 1) do |j|
            if i >= 0 && i < board.length && j >= 0 && j < board.length && (i != row || j != col)
                if board[i][j] == 1
                    neighbors << [i, j]
                end
            end
        end
    end
    neighbors
end

def update(board)
    old_board = Marshal.load(Marshal.dump(board))
    updated_board = board

    old_board.each_with_index do |line, row|
        line.each_with_index do |cell, col|
            neighbors = get_neighbors(row, col, old_board)
            if cell == 1
                # under-population and over-population
                if neighbors.length < 2 || neighbors.length > 3
                    updated_board[row][col] = 0
                end
            else
                # reproduction
                if neighbors.length == 3
                    updated_board[row][col] = 1
                end
            end
        end
    end
    updated_board
end

def print_board(board)
    board.each do |line|
        line.each do |cell|
            print cell == 1 ? "*" : "."
        end
        puts
    end
end

lines = []
File.open(ARGV[0], 'r').each_line do |line|
    lines << line
end

N = lines.length
board = Array.new(N) { Array.new(N, 0) }

lines.each_with_index do |line, row|
    line.chomp.split("").each_with_index do |cell, col|
        if cell == "*"
            board[row][col] = 1
        end
    end
end

1.upto(10) do |x|
    board = update(board)
end

print_board(board)