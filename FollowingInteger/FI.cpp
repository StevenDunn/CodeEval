// Following Integer solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      cout << line << endl;
    }
    inputFile.close();
  }
  return 0;
}
