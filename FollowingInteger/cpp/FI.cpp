// Following Integer solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>

using std::ifstream;
using std::next_permutation;
using std::sort;
using std::string;

string parse_digits(string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      int original = atoi(line.c_str());
      string digits = parse_digits(line);
      sort(digits.begin(), digits.end());
      while (next_permutation(digits.begin(), digits.end()))
      {
        int val = atoi(digits.c_str());
        if (val > original)
        {
          printf("%d\n", val);
          break;
        }
      }
    }
    inputFile.close();
  }
  return 0;
}

string parse_digits(string line)
{
  sort(line.begin(), line.end());
  int remaining = 6 - line.size();
  string padding;
  for (int i = 0; i < remaining; ++i)
    padding += "0";
  return (padding + line);
}