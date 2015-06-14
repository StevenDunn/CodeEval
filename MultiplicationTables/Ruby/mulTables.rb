# multiplication tables solution in ruby for codeeval. com by steven a dunn

for i in (1...13)
    for j in (1...13)
        if j == 1
            printf("%2d" % (i * j))
        else
            printf("%4d" % (i * j))
        end
    end
    puts
end