// Predict the number solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

long calculate(long);

int main (int argc, char* const argv[])
{
  ifstream input_file(argv[1]);
  string line;
  if (input_file)
  {
    while (getline(input_file, line))
    {
      long n = atol(line.c_str());
      long x = calculate(n);
      int offset = 0;
      while (n > 0)
      {
        n -= x;
        offset++;
        x = calculate(n);
      }
      cout <<  offset % 3 << endl;
    }
    input_file.close();
  }
  return 0;
}

long calculate(long n)
{
  long x = 2;
  while (x <= n)
    x *= 2;
  return x/2;
}