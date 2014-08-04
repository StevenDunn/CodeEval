# simple calc soln in rb for codeeval by steven a dunn

PAR_RGX = //

NEG_RGX = //

EXP_RGX = /(\d+\.?\d*\s*)(\^){1}(\s*\d+\.?\d*)/

MLT_RGX = /(\d+\.?\d*\s*)(\*){1}(\s*\d+\.?\d*)/
DIV_RGX = /(\d+\.?\d*\s*)(\/){1}(\s*\d+\.?\d*)/

ADD_RGX = /(\d+\.?\d*\s*)(\+){1}(\s*\d+\.?\d*)/
SUB_RGX = /(\d+\.?\d*\s*)(\-){1}(\s*\d+\.?\d*)/

def eval(line)
    if line =~ EXP_RGX
        operand1, operator, operand2 = line.match(EXP_RGX).captures
        result = ((operand1).to_f ** (operand2).to_f).to_s
        line.gsub!(EXP_RGX, result)
        puts line
    end

    if line =~ MLT_RGX
        operand1, operator, operand2 = line.match(MLT_RGX).captures
        result = ((operand1).to_f * (operand2).to_f).to_s
        line.gsub!(MLT_RGX, result)
        puts line
    end

    if line =~ DIV_RGX
        operand1, operator, operand2 = line.match(DIV_RGX).captures
        result = ((operand1).to_f / (operand2).to_f).to_s
        line.gsub!(DIV_RGX, result)
        puts line
    end

    if line =~ ADD_RGX
        operand1, operator, operand2 = line.match(ADD_RGX).captures
        result = ((operand1).to_f + (operand2).to_f).to_s
        line.gsub!(ADD_RGX, result)
        puts line
    end

    if line =~ SUB_RGX
        operand1, operator, operand2 = line.match(SUB_RGX).captures
        result = ((operand1).to_f - (operand2).to_f).to_s
        line.gsub!(SUB_RGX, result)
        puts line
    end

=begin
    operand1, operator, operand2 = line.match(MLT_RGX).captures
    result = operand1.to_f * operand2.to_f
    line.gsub!(MLT_RGX, result.to_s)
=end

    puts line
end

File.open(ARGV[0], 'r').each_line do |line|
    puts line
    puts eval(line)
end