# color code converter soln in py3 for code eval by steven a dunn

import sys, re, math

def hue2rgb(p, q, t):
    if t < 0:
        t += 1
    if t > 1:
        t -= 1
    if t < 1/6.0:
        return p + (q - p) * 6 * t
    if t < 1/2.0:
        return q
    if t < 2/3.0:
        return p + (q - p) * (2/3.0 - t) * 6
    return p

def hsl2rgb(line):
    vals = list(map(float, line.rstrip()[4:-1].split(",")))
    hue = vals[0]/360.0
    s = vals[1]/100.0
    l = vals[2]/100.0

    if l < 0.5:
        q = l * (1 + s)
    else:
        q = l + s - l * s
    p = 2 * l - q

    r = hue2rgb(p, q, hue + 1/3.0)
    g = hue2rgb(p, q, hue)
    b = hue2rgb(p, q, hue - 1/3.0)
    rgb = [round(x * 255) for x in [r,g,b]]
    return rgb

def hsv2rgb(line):
    vals = list(map(float, line.rstrip()[4:-1].split(",")))
    hue = vals[0]/360
    saturation = vals[1]/100
    value = vals[2]/100

    i = math.floor(hue * 6)
    f = (hue * 6) - i
    p = value * (1 - saturation)
    q = value * (1 - f * saturation)
    t = value * (1 - (1 - f) * saturation)

    switch = i % 6
    if switch == 0:
        r = value
        g = t
        b = p
    elif switch == 1:
        r = q
        g = value
        b = p
    elif switch == 2:
        r = p
        g = value
        b = t
    elif switch == 3:
        r = p
        g = q
        b = value
    elif switch == 4:
        r = t
        g = p
        b = value
    elif switch == 5:
        r = value
        g = p
        b = q

    rgb = [r * 255, g * 255, b * 255]
    rgb = [round(x) for x in rgb]
    return rgb

def cmyk2rgb(line):
    vals = list(map(float, line.rstrip()[1:-1].split(",")))
    c = vals[0]
    m = vals[1]
    y = vals[2]
    k = vals[3]

    r = 255 * (1 - c) * (1 - k)
    g = 255 * (1 - m) * (1 - k)
    b = 255 * (1 - y) * (1 - k)

    rgb = [r, g, b]
    rgb = [round(x) for x in rgb]
    return rgb

def hex2rgb(line):
    line = line.rstrip()[1:]
    r = int(line[0:2],16)
    g = int(line[2:4], 16)
    b = int(line[4:6], 16)
    return [r,g,b]

HSL_REGEX = r'^HSL'
HSV_REGEX = r'^HSV'
CMYK_REGEX = r'^\('
HEX_REGEX = r'^#'

f = open(sys.argv[1], 'r')
for line in f:
    rgb = None

    match = re.search(HSL_REGEX, line)
    if match:
        rgb = hsl2rgb(line)

    match = re.search(HSV_REGEX, line)
    if match:
        rgb = hsv2rgb(line)

    match = re.search(CMYK_REGEX, line)
    if match:
        rgb = cmyk2rgb(line)

    match = re.search(HEX_REGEX, line)
    if match:
        rgb = hex2rgb(line)

    sys.stdout.write("RGB(%d,%d,%d)\n" % (rgb[0], rgb[1], rgb[2]))
f.close()