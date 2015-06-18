# age distribution solution in ruby for codeeval.com by steven a dunn

File.open(ARGV[0], 'r').each_line do |line|
    line = line.to_i
    if line < 0
        puts "This program is for humans"
    elsif line <= 2
        puts "Still in Mama's arms"
    elsif line <= 4
        puts "Preschool Maniac"
    elsif line <= 11
        puts "Elementary school"
    elsif line <= 14
        puts "Middle school"
    elsif line <= 18
        puts "High school"
    elsif line <= 22
        puts  "College"
    elsif line <= 65
        puts "Working for the man"
    elsif line <= 100
        puts "The Golden Years"
    else
        puts "This program is for humans"
    end
end