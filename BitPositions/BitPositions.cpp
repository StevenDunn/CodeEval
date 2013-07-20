// Bit Positions program written in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

string ConvertToBinary(const int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);

  string line;

  if(inputFile)
  {
    long n, p1, p2 = 0;

    while(getline(inputFile, line))
    {
      size_t commaPos1 = line.find(",");
      stringstream ssn(line.substr(0, commaPos1));
      ssn >> n;

      size_t commaPos2 = line.substr(commaPos1+1).find(",");
      stringstream ssp1(line.substr(commaPos1+1, commaPos1+commaPos2));
      ssp1 >> p1;

      stringstream ssp2(line.substr(commaPos1+commaPos2+2));
      ssp2 >> p2;

      string result = ConvertToBinary(n);

      result[result.length()-p1] == result[result.length()-p2] ? cout << "true" << endl : cout << "false" << endl;
      
    }
    inputFile.close();
  }
  else perror("UNABLE TO OPEN FILE");

  return 0;
}

string ConvertToBinary(const int n)
{
  int remainder;
  string result;
  char letter;

  stringstream ssn;
  ssn << n;

  if(n <= 1)
  {
    result.append(ssn.str());
    return result;
  }
  remainder = n%2;
  result = ConvertToBinary(n >> 1);
 
  stringstream ssr;
  ssr << remainder;
  result.append(ssr.str());

  return result;
}