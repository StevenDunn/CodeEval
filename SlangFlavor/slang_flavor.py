#slang flavor soln in py for codeeval by steven a dunn

import sys

f = open(sys.argv[1], 'r')

is_slang = False
slang_index = 0
slang = [", yeah!", ", this is crazy, I tell ya.", ", can U believe this?", ", eh?", ", aw yea.", ", yo.", "? No way!", ". Awesome!"]
for line in f:
    new_line = line
    offset = 0
    for index, c in enumerate(line):
        if c == "." or c == "?" or c == "!":
            if is_slang:
                new_line = new_line[0:index+offset] + slang[slang_index] + new_line[index+offset+1:]
                offset += len(slang[slang_index]) - 1
                slang_index += 1
                if slang_index >= 8:
                    slang_index = 0
            is_slang = not is_slang
    new_line = new_line.rstrip()
    print new_line
f.close()