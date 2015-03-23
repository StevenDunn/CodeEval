// Minimum Coins solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int numCoins(int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      int N = atoi(line.c_str());
      cout << numCoins(N) << endl;
    }
    inputFile.close();
  }

  return 0;
}

int numCoins(int N)
{
  int count = 0;
  while (N >= 5)
  {
    N -= 5;
    ++count;
  }
  while (N >= 3)
  {
    N -= 3;
    ++count;
  }

  count += N;  
  
  return count;
}
