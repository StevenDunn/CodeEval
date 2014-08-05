# simple calc soln in rb for codeeval by steven a dunn

EXP_RGX = /(\-?\d+\.?\d*\s*)(\^){1}(\s*\-?\d+\.?\d*)/

MLT_RGX = /(\-?\d+\.?\d*\s*)(\*){1}(\s*\-?\d+\.?\d*)/
DIV_RGX = /(\-?\d+\.?\d*\s*)(\/){1}(\s*\-?\d+\.?\d*)/

ADD_RGX = /(\-?\d+\.?\d*\s*)(\+){1}(\s*\-?\d+\.?\d*)/
SUB_RGX = /(\-?\d+\.?\d*\s*)(\-){1}(\s*\-?\d+\.?\d*)/

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
    line.gsub!(/\-\-/, "")
#puts "line after paren resolution: #{line}"
    # resolve exps
    while line =~ EXP_RGX
        operand1, operator, operand2 = line.match(EXP_RGX).captures
        result = ((operand1).to_f ** (operand2).to_f)
        if result == Float::INFINITY
            result = 200001
        end
        line.sub!(EXP_RGX, result.to_s)
    end
#puts "line after exp: #{line}"
    # scan left to right resolving mults and divs
    line.split("").each do |char|
        if char == "*"
            operand1, operator, operand2 = line.match(MLT_RGX).captures
            result = ((operand1).to_f * (operand2).to_f).to_s
            line.sub!(MLT_RGX, result)
        elsif char == "/"
            operand1, operator, operand2 = line.match(DIV_RGX).captures
            result = ((operand1).to_f / (operand2).to_f).to_s
            line.sub!(DIV_RGX, result)
        end
    end
#puts "line after mult/div: #{line}"
    # scan left to right resolving adds and subs
    line.split("").each_with_index do |char, index|
        if char == "+"
            operand1, operator, operand2 = line.match(ADD_RGX).captures
            result = ((operand1).to_f + (operand2).to_f).to_s
            line.sub!(ADD_RGX, result)
        elsif char == "-" && index != 0 && line[index-1] == " " && line[index+1] == " "
            operand1, operator, operand2 = line.match(SUB_RGX).captures
            result = ((operand1).to_f - (operand2).to_f).to_s
            line.sub!(SUB_RGX, result)
        end
    end
#puts "line after add/sub: #{line}"
    line = resolve_parens(line)
end

File.open(ARGV[0], 'r').each_line do |line|
    #puts line
    result = eval(line).to_f
    result == result.floor ? printf("%i\n", result.to_i) : printf("%.5f\n", result)

end