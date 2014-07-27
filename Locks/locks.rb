# locks soln in rb for codeeval by steven a dunn

OPEN = false
CLOSED = true

UNLOCKED = false
LOCKED = true

class Door
    attr_accessor :lock, :door

    def initialize
        @lock = UNLOCKED
        @door = OPEN
    end

    def close
        @door = CLOSED
        @lock = LOCKED
    end

    def toggle_lock
        @lock = !@lock
    end
end


File.open(ARGV[0], 'r').each_line do |line|
    line = line.split(' ')
    num_locks = line[0].to_i
    repetitions = line[1].to_i

    locks = Array.new(num_locks) { Door.new }

    0.upto(repetitions - 2) do |n|
        0.upto(num_locks - 1) do |x|
            if (x+1) % 2 == 0
                locks[x].close
            end
            if (x+1) % 3 == 0
                locks[x].toggle_lock
            end
        end
    end

    # final repetition
    locks[-1].toggle_lock

    num_unlocked = 0
    locks.each do |lock|
        if lock.lock == UNLOCKED
            num_unlocked += 1
        end
    end

    puts num_unlocked
end