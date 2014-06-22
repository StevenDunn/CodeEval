// String Rotation solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

string isRotation(string, string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      int commaPos = line.find(",");
      string text = line.substr(0, commaPos);
      string possibleRotation = line.substr(commaPos + 1);
      cout << isRotation(text, possibleRotation) << endl; 
    }
    inputFile.close();
  }
  
  return 0;
}

string isRotation(string text, string possibleRotation)
{
  string doubledLine = text;
  doubledLine.append(text);

  if (doubledLine.find(possibleRotation) != string::npos)
    return "True";

  return "False";
}
