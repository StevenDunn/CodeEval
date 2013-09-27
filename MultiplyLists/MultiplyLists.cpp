// Multiply Lists solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

void multiplyLines(string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      multiplyLines(line);
      cout << endl;
    }
    inputFile.close();
  }

  return 0;
}

void multiplyLines(string line)
{
  string line1 = line.substr(0, line.find("|"));
  string line2 = line.substr(line.find("|") + 1);

  stringstream ss1(line1);
  stringstream ss2(line2);

  string word1;
  string word2;

  while(ss1 >> word1 && ss2 >> word2)
    cout << atoi(word1.c_str()) * atoi(word2.c_str()) << " "; 
}
