# working experience solution in ruby for code eval by steven a dunn
require 'date'
require 'set'

input = ARGV[0]

def get_ranges(dates)
  ranges = Set.new
  dates.each do |date_range|
      start = Date.parse(date_range[0])
      finish = (Date.parse(date_range[1]) >> 1) - 1
      date = (start..finish)
      ranges.merge(date)
    end
  ranges
end

File.open(input, 'r') do |file|
  while line = file.gets
    dates = line.split(';').map! {|x| x.split('-')}
    ranges = get_ranges(dates)
    puts ranges.length/365
  end
 end