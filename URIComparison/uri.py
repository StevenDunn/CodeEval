# URI Comparison solutionin Python 2 for CodeEval.com by Steven A. Dunn

def get_encoded_symbol(encoded_char):
  val = int(encoded_char, 16)
  result = ""
  if val == 126: result = "~"
  return result

def parse_uri(uri):
  port_colon_pos = uri[:(uri.find(':') + 1)].find(':')
  if port_colon_pos < 0: 
    com_pos = uri.find("com")
    uri = uri[0:com_pos+3] + ":80" + uri[com_pos+4:]
  elif uri[port_colon_pos + 6] == '/':
    uri = uri[0:port_colon_pos+6] + "80" + uri[port_colon_pos+7:]

  for i in range(0, len(uri)):
    if uri[i] == '%':
      encoded_char = uri[i+1:i+3]
      uri = uri[0:i] + get_encoded_symbol(encoded_char) + uri[i+1:]
  uri = uri.lower()
  return uri

def uri_compare(uri1, uri2):
  parsed_uri1 = parse_uri(uri1)
  parsed_uri2 = parse_uri(uri2)

  print "parse uris: ", uri1, uri2

  if parsed_uri1 == parsed_uri2: return True
  else: return False

import sys

for line in open(sys.argv[1], 'r'):
  line = line.rstrip('\n').split(';')
  uri1, uri2 = line[0], line[1]

  if uri_compare(uri1, uri2): print True
  else: print False
