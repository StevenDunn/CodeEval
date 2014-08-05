# simple calc soln in rb for codeeval by steven a dunn

EXP_RGX = /(\-?\d+\.?\d*\s*)(\^){1}(\-?\s*\d+\.?\d*)/

MLT_RGX = /(\-?\d+\.?\d*\s*)(\*){1}(\-?\s*\d+\.?\d*)/
DIV_RGX = /(\-?\d+\.?\d*\s*)(\/){1}(\-?\s*\d+\.?\d*)/

ADD_RGX = /(\-?\d+\.?\d*\s*)(\+){1}(\-?\s*\d+\.?\d*)/
SUB_RGX = /(\-?\d+\.?\d*\s*)(\-){1}(\-?\s*\d+\.?\d*)/

def resolve_parens(line)
    parens = []
    updated_line = line
    line.split("").each_with_index do |char, index|
        if char == "("
            parens << index
        elsif char == ")"
            start = parens.pop
            finish = index
            updated_line[start..finish] = eval(line[start+1..finish-1])
            return updated_line
        end
    end
    line
end

def eval(line)
    # resolve parens recursively
    # I realize this is a bit hacky
    updated_line = resolve_parens(line)
    while updated_line =~ /\(/
        updated_line = resolve_parens(line)
    end
    line = updated_line

    # resolve exps
    while line =~ EXP_RGX
        operand1, operator, operand2 = line.match(EXP_RGX).captures
        result = ((operand1).to_f ** (operand2).to_f).to_s
        line.gsub!(EXP_RGX, result)
    end

    # scan left to right resolving mults and divs
    line.split("").each do |char|
        if char == "*"
            operand1, operator, operand2 = line.match(MLT_RGX).captures
            result = ((operand1).to_f * (operand2).to_f).to_s
            line.gsub!(MLT_RGX, result)
        elsif char == "/"
            operand1, operator, operand2 = line.match(DIV_RGX).captures
            result = ((operand1).to_f / (operand2).to_f).to_s
            line.gsub!(DIV_RGX, result)
        end
    end

    # scan left to right resolving adds and subs
    line.split("").each do |char|
        if char == "+"
            operand1, operator, operand2 = line.match(ADD_RGX).captures
            result = ((operand1).to_f + (operand2).to_f).to_s
            line.gsub!(ADD_RGX, result)
        elsif char == "-" && line =~ SUB_RGX
            operand1, operator, operand2 = line.match(SUB_RGX).captures
            result = ((operand1).to_f - (operand2).to_f).to_s
            line.gsub!(SUB_RGX, result)
        end
    end

    line = resolve_parens(line)
end

File.open(ARGV[0], 'r').each_line do |line|
    puts line
    result = eval(line).to_f
    result == result.floor ? printf("%i\n", result.to_i) : printf("%.5f\n", result)

end