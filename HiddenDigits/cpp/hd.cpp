// Hidden digits solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

bool printHiddenDigits(string);
bool findHiddenDigits(char);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      if(!printHiddenDigits(line))
        cout << "NONE";
      cout << endl;
    } 
    inputFile.close();
  }

  return 0;
}

bool printHiddenDigits(string line)
{
  bool isEmpty = true;
  for(int idx = 0; idx < line.size(); ++idx)
    if(findHiddenDigits(line[idx]))
      isEmpty = false;
  return !isEmpty;
}

bool findHiddenDigits(char c)
{
  bool charFound = true;
  switch(c)
  {
    case 'a':
    case '0':
      cout << 0;
      break;
    case 'b':
    case '1':
      cout << 1;
      break;
    case 'c':
    case '2':
      cout << 2;
      break;
    case 'd':
    case '3':
      cout << 3;
      break;
    case 'e':
    case '4':
      cout << 4;
      break;
    case 'f':
    case '5':
      cout << 5;
      break;
    case 'g':
    case '6':
      cout << 6;
      break;
    case 'h':
    case '7':
      cout << 7;
      break;
    case 'i':
    case '8':
      cout << 8;
      break;
    case 'j':
    case '9':
      cout << 9;
      break;
    default:
      charFound = false;
      break;
  }
  return charFound;
}
