# color code converter soln in rb for codeeval by steven a dunn

def hue2rgb(p, q, t)
    if (t < 0)
        t += 1
    end
    if (t > 1)
        t -= 1
    end
    if (t < 1/6.0)
        return p + (q - p) * 6 * t
    end
    if (t < 1/2.0)
        return q
    end
    if (t < 2/3.0)
        return p + (q - p) * (2/3.0 - t) * 6
    end
    p
end

def hsl2rgb(line)
    vars = line.chomp[4..-2].split(',').map(&:to_f)

    hue = vars[0]/360.0
    s = vars[1]/100.0
    l = vars[2]/100.0

    if (l < 0.5)
        q = l * (1 + s)
    else
        q = l + s - l * s
    end
    p = 2 * l - q

    r = hue2rgb(p, q, hue + 1/3.0)
    g = hue2rgb(p, q, hue)
    b = hue2rgb(p, q, hue - 1/3.0)
    rgb = [r,g,b].map{|x| x * 255}
    rgb.map!(&:round)
end

def hsv2rgb(line)
    vars = line.chomp[4..-2].split(',').map(&:to_f)

    hue = vars[0]/360
    saturation = vars[1]/100
    value = vars[2]/100

    i = (hue * 6).floor
    f = (hue * 6) - i
    p = value * (1 - saturation)
    q = value * (1 - f * saturation)
    t = value * (1 - (1 - f) * saturation)

    case (i % 6)
    when 0
        r = value
        g = t
        b = p
    when 1
        r = q
        g = value
        b = p
    when 2
        r = p
        g = value
        b = t
    when 3
        r = p
        g = q
        b = value
    when 4
        r = t
        g = p
        b = value
    when 5
        r = value
        g = p
        b = q
    end

    rgb = [r * 255, g * 255, b * 255]
    rgb.map!(&:round)
end

def cmyk2rgb(line)
    vars = line.chomp[1..-2].split(',').map(&:to_f)
    c = vars[0]
    m = vars[1]
    y = vars[2]
    k = vars[3]

    r = 255 * (1 - c) * (1 - k)
    g = 255 * (1 - m) * (1 - k)
    b = 255 * (1 - y) * (1 - k)

    rgb = [r, g, b]
    rgb.map!(&:round)
end

def hex2rgb(line)
    line = line.chomp[1..-1]
    r = line[0..1].to_i(16)
    g = line[2..3].to_i(16)
    b = line[4..5].to_i(16)

    [r,g,b]
end

HSL_REGEX = /^HSL/
HSV_REGEX = /^HSV/
CMYK_REGEX = /^\(/
HEX_REGEX = /^#/

File.open(ARGV[0], 'r').each_line do |line|
    rgb = nil
    if line =~ HSL_REGEX
        rgb = hsl2rgb(line)
    elsif line =~ HSV_REGEX
        rgb = hsv2rgb(line)
    elsif line =~ CMYK_REGEX
        rgb = cmyk2rgb(line)
    elsif line =~ HEX_REGEX
        rgb = hex2rgb(line)
    end
    puts "RGB(#{rgb[0]},#{rgb[1]},#{rgb[2]})"
end