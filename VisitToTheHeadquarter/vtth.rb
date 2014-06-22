# visiting the headquarters solution in ruby for code eval by steven a dunn
require 'time'

class Agent

  @start_time = nil
  @time = nil
  @seniority = nil
  @itinerary = nil
  @current_floor = nil
  @current_room = nil

  def initialize(seniority, start_time)
    @start_time = Time.parse(start_time)
    @time = Time.parse(start_time)
    @seniority = seniority
    @itinerary = Array.new
    @current_floor = 1
    @current_room = Room.new(-1)
  end

  def enter_building
    @time += 10
  end

  def exit_building
    @time += 10
  end

  def move_to_room(room_number)
    @current_room = room_number
    @time += 10 + @itinerary[0][1].to_i

  end

  def move_to_elevator
    @time += 10
  end

  def move_to_adjacent_floor
    @time += 10
  end

  def use_elevator(elevator)
  end

  def add_to_itinerary(entry)
    @itinerary.push(entry)
  end

  def remove_from_itinerary(entry)
    @itinerary.remove(entry)
  end

  def itinerary
    @itinerary
  end
 
  def start_time
    @start_time
  end

  def time
    @time
  end

  def move_to_next_room
    next_floor = @itinerary[0][0].slice(0, 2).to_i
    next_room = $rooms[@itinerary[0][0].slice(2, 2)]
        
    if next_floor != @current_floor
      # board elevator
      puts "boarding elevator"
    else
      if next_room == @current_room
        # => in room queue
        puts "in room queue"
      else
        if next_room.is_room_available?
          move_to_room(next_room) 
        else
          next_room.enqueue(@this)  
        end
      end
    end  
  end
end

# =======

class Room
  @number = nil
  @is_room_available = nil
  @queue = []

  def initialize(number)
    @number = number
    @is_room_available = true
  end

  def room_available?
    @is_room_available
  end

  def enqueue(agent)
  end

  def dequeue
  end
end

# =======

class Elevator
  @floor_1 = nil
  @floor_2 = nil
  @is_elevator_available = nil
  @direction = nil
  @queue = []

  def initialize
  end

  def elevator_available?
    @is_elevator_available
  end

  def enqueue
  end

  def dequeue
  end
end

# =======

def arrive(agents)
  agents.each do |agent|
    agent.enter_building
  end
end

def finished?(agents)
  agents.each do |agent|
    if !agent.itinerary.nil?
      return false
    end
  end
  true
end

def leave(agents)
  agents.each do |agent|
    agent.exit_building
  end
end

def visit(agents)
  arrive(agents)
  while !finished?(agents)
    agents.each do |agent|
      agent.move_to_next_room
    end
    break 
  end
  leave(agents)
end

def display_time_visited(agents)
  agents.each do |agent|
    puts "#{agent.start_time.strftime("%H:%M:%S")} #{agent.time.strftime("%H:%M:%S")}"
  end
end

agents = Array.new
$rooms = Hash.new

File.open(ARGV[0]).each_line do |line|
  line = line.split
  agent_seniority = line[0]
  agent_start_time = line[1]

  agent = Agent.new(agent_seniority, agent_start_time)

  room_number = nil
  time = nil
  (2..line.length-1).each do |i|
    if i % 2 == 0 
      room_number = line[i]
      $rooms[room_number] = []
    else
      time = line[i]
      agent.add_to_itinerary [room_number, time]
    end
  end
  agents.push(agent)
end

visit(agents)

display_time_visited(agents)
