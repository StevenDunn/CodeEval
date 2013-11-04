# Endianness solution in Python 2 for CodeEval.com by Steven A. Dunn

import sys
if sys.byteorder == 'little': print "LittleEndian"
else: print "BigEndian"
