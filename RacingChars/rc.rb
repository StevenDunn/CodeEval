# racing chars solution in ruby for code eval by steven a dunn

input_file = ARGV[0]

def update_dir(prev, index)
  dir = nil
  if index < prev
    dir = '/'
  elsif index == prev
    dir = '|'
  else
    dir = "\\"
  end
  dir
end

File.open(input_file, "r") do |file|
  dir = '|'
  prev = nil
  while line = file.gets
    gate_index = line.index('_')
    if prev.nil? 
      prev = gate_index 
    end

    checkpoint_index = line.index('C')
    if checkpoint_index.nil? 
      dir = update_dir(prev, gate_index)
      line[gate_index] = dir
      prev = gate_index
    else
      dir = update_dir(prev, checkpoint_index)
      line[checkpoint_index] = dir
      prev = checkpoint_index
    end

    puts line 
  end
end
