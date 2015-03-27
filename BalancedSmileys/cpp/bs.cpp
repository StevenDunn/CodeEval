// Balanced Smileys solution in C++ for CodeEval.com by Steven A. Dunn

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using std::abs;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

string isBalanced(string);
string replaceSmileys(string);
void replaceAll(string&, string, string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
      cout << isBalanced(line) << endl;
    inputFile.close();
  }
  return 0;
}

string isBalanced(string line)
{
  if (line == "")
    return "YES";

  line = replaceSmileys(line);
 
  int min = 0;
  int max = 0;
  int leftParenFound = 0;
  for (int i = 0; i < line.size(); ++i)
  {
    char c = line[i];
    if (c == '(') 
    {
      ++min;
      ++max;
    }
    else if (c == ')') 
    {
      --min;
      --max;
      if (max < 0) { return "NO"; }
    }
    else if (c == '{') 
    {
      ++max;
    }
    else if (c == '}') 
    {
      --min;
    }   
  }
 
  if (min <= 0 && 0 <= max)
    return "YES"; 

  return "NO";
}

string replaceSmileys(string line)
{
  string replacedLine = line;
  replaceAll(replacedLine, ":)", "}");
  replaceAll(replacedLine, ":(", "{"); 
  return replacedLine;
}

void replaceAll(string& line, string from, string to)
{
  int start = 0;
  while((start = line.find(from, start)) != string::npos)
  {
    line.replace(start, from.length(), to);
    start + to.length();
  }
}
