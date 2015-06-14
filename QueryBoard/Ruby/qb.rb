# query board soln in rb for codeeval.com by steven a dunn

$board = []
(0..256).each do
  $board << ([0]*256)
end


def parseCommand(command, param1, param2)
    param1 = param1.to_i
    if param2
        param2 = param2.to_i
    end
    sum = 0

    if command == "SetRow"
        (0...256).each do |i|
            $board[i][param1] = param2
        end
    elsif command == "SetCol"
        (0...256).each do |j|
            $board[param1][j] = param2
        end
    elsif command == "QueryRow"
        (0...256).each do |i|
            sum += $board[i][param1]
        end
        puts sum
    elsif command == "QueryCol"
        (0...256).each do |j|
            sum += $board[param1][j]
        end
        puts sum
    end
end

File.open(ARGV[0], 'r').each_line do |line|
    line = line.chomp.split(' ')
    command = line[0]
    param1 = line[1]
    param2 = ""
    if line.length > 2
        param2 = line[2]
    end
    parseCommand(command, param1, param2)
end