# ministry of truth solution in ruby for codeeval by steven a dunn

module Enumerable
    def sorted?
        each_cons(2).all? { |a, b| (a <=> b) <= 0}
    end
end

def print_revised_text(text, indices, revision)
    revised_text = ""
    index = 0
    while index < text.length
        if indices.include?(index)
            revised_text[index..(index + revision[0].length)] = revision[0]
            index += revision[0].length
            revision.delete_at(0)
            next
        elsif text[index] == " "
            revised_text << " "
        else
            revised_text << "_"
        end
        index += 1
    end
    puts revised_text
end

File.open(ARGV[0], 'r').each_line do |line|
    text, revision = line.split(";")
    #puts line
    text.gsub!(/\s+/, ' ')
    split_text = text.split(" ")

    revision = revision.split

    indices = []
    matched_words = []
    invalid = nil
    revision.each do |word|
        index = text.index(word)
        matches = split_text.select { |e| /#{word}/ =~ e }
        #puts "#{matches}"
        match = matches[0]
        matches.each do |entry|
            if indices.empty?
                if !matched_words.include?(entry)
                    match = entry
                    index = text.index(word, text.index(match))
                    break
                end

            elsif !matched_words.include?(entry) && text.index(entry) > indices[-1]
                match = entry
                index = text.index(word, text.index(match))
                break
            end
        end

        if !index.nil? && !matched_words.include?(match)
            indices << index
            matched_words << match
        else
            invalid = true
            break
        end
    end

    if !indices.sorted? || invalid
        puts "I cannot fix history"
    else
        print_revised_text(text, indices, revision)
    end
end