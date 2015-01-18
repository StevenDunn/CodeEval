// Shortest Repetition solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int getSmallestPeriod(string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      cout << getSmallestPeriod(line) << endl;
    }
    inputFile.close();
  }
  return 0;
}

int getSmallestPeriod(string line)
{
  char firstChar = line[0];
  int repIdx = 1;

  for(int i = 1; i < line.length(); ++i)
  {
    if(line[i] == firstChar)
      break;
    ++repIdx;
  }
  return repIdx;
}
