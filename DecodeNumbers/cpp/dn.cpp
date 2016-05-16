// Decode Numbers solution in C++ for CodeEval.com by Steven A. Dunn

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

int getCount(string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;
  if (inputFile)
  {
    while (getline(inputFile, line))
      cout << getCount(line) << endl;
    inputFile.close();
  }

  return 0;
}

int getCount(string line)
{
  int count = 0;
  int val;
  if (line.size() == 1 && line.at(0) != '0')
    return 1;
  if (line.size() == 2)
  {
    val = atoi(line.c_str());
    if (line.at(0) == '0' || val > 26)
      return 0;
    if (line.at(1) == '0')
      return 1;
    else
      return 2;
  }

  for(int i = 0; i < line.size() - 1; ++i)
  {
    string sub = line.substr(i, i+2);
    if (sub.at(0) == '0' || sub.at(1) == '0')
    {
      ++count;
      continue;
    }
    val = atoi(sub.c_str());   
    if (val > 26)
      ++count;
    else
      count = count + 2;     
  }  

  return (count - (line.size() - 2));
}
