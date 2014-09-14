# word chain soln in rb for codeeval by steven a dunn

class Node
    attr_accessor :name

    def initialize(letter)
        @name = letter
        @links = {}
        @link_count = {}
    end

    def add(node)
        if @links.has_key? node.name
            @link_count[node.name] += 1
        else
            @link_count[node.name] = 1
            @links[node.name] = node
        end
    end

    def get_longest_chain
        length = 0

        @link_count.each do |name, count|
            if count > 0
                @link_count[name] -= 1
                length = [length, @links[name].get_longest_chain + 1].max
                @link_count[name] += 1
            end
        end

        length
    end
end

File.open(ARGV[0], 'r').each_line do |line|
    words = line.chomp.split(',')

    # create a graph of letters
    nodes = {}
    words.each do |word|
        start_letter = word[0]
        if !nodes.has_key? start_letter
            nodes[start_letter] = Node.new(start_letter)
        end

        end_letter = word[-1]
        if !nodes.has_key? end_letter
            nodes[end_letter] = Node.new(end_letter)
        end

        # create an edge between the start letter and the end letter
        nodes[start_letter].add(nodes[end_letter])
    end

    chain_length = 0
    nodes.each do |letter, node|
        longest_chain = node.get_longest_chain
        if longest_chain > chain_length
            chain_length = longest_chain
        end
    end

    if chain_length <= 1
        puts "None"
    else
        puts chain_length
    end
end