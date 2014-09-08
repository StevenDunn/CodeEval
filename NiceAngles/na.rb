# nice angles soln in rb for codeeval by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    angle = line.to_f
    full_degree = angle.floor
    remaining_angle = angle - full_degree
    minutes = (remaining_angle * 60).floor
    seconds = (((remaining_angle * 60) - minutes) * 60).floor
    printf("%d.%02d'%02d\"\n", full_degree, minutes, seconds)
end