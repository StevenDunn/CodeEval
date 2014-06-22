def simplify(sequence)
    current_char = sequence[0]
    simplified_string = current_char
    sequence.split("").each do |c|
        if c != current_char
            current_char = c
            simplified_string << current_char
        end
    end
    simplified_string
end

def convert(string)
    translations = []
    a = ["1", "0", "10", "01"]

    string[0] == 'A' ? translations.concat(a) : translations = ["1"]

    string[1..-1].split("").each do |c|
        if c == 'A'
            translations.map!{ |t|
                updated_vals = []
                a.each do |x|
                    updated_vals << t + x
                end
                t = updated_vals
            }
            translations.flatten!
        else
            translations.map!{ |x| x + "1" }
        end
    end
    translations.flatten
end

def validTranslation?(translations, binary)
    translations.include?(binary) ? "Yes" : "No"
end

File.open(ARGV[0], 'r') do |file|
    while line = file.gets
        binary, sequence = line.split
        simplified_string = simplify(sequence)
        simplified_binary = simplify(binary)
        translations = convert(simplified_string)

        puts validTranslation?(translations, simplified_binary)
    end
end