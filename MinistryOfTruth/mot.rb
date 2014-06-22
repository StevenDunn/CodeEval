# ministry of truth solution in ruby for codeeval by steven a dunn

module Enumerable
    def sorted?
        each_cons(2).all? { |a, b| (a <=> b) <= 0}
    end
end

File.open(ARGV[0], 'r') do |file|
    while line = file.gets
        text, revision = line.split(";")
        text.gsub!(/\s+/, ' ')

        revision = revision.split
        indices = []
        revision.each do |word|
            index = text.index(word)
            if !index.nil?
                indices << index
            end
        end
        puts indices
        if indices.nil? || !indices.sorted?
            puts "I cannot fix history"
        else
            puts "works"
        end
    end
end