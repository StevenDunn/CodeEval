// Multipes of a Number program written in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);

  string line;
  int x, n = 0;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      size_t commaPos = line.find(",");
      stringstream ssx(line.substr(0, commaPos));
      ssx >> x;

      stringstream ssn(line.substr(commaPos+1));
      ssn >> n;    
     
      while(x >= n)
      {
        n*=2;
      }
      cout << n << endl;
    }
    inputFile.close();
  }
  else perror("UNABLE TO OPEN FILE");

  return 0;
}