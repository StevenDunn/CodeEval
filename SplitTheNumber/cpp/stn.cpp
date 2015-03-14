// Split the Number C++ soln for Code Eval by Steven A Dunn

#include <fstream>
#include <string>

using std::ifstream;
using std::string;

void split_the_number(string);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while( getline(input_file, line))
        {
            split_the_number(line);
        }
        input_file.close();
    }
    return 0;
}

void split_the_number(string line)
{

}

/*
# Split the number soln in Python for CodeEval.com by Steven A. Dunn

import sys

for line in open(sys.argv[1], 'r'):
  expr = line.rstrip('\n').split(' ')
  expr[0] = list(expr[0])

  for i in range(0, len(expr[1])):
    if expr[1][i] == '+':
      expr[0].insert(i, '+')
    elif expr[1][i] == '-':
      expr[0].insert(i, '-')
    else:
      continue

  result = ''.join(expr[0])

  print eval(result)

 */