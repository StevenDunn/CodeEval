// Valid Parentheses solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::stack;
using std::string;

string isValid(string);
string compare(char c, stack<char>&);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
      cout << isValid(line) << endl;
    inputFile.close();
  }

  return 0;
}

string isValid(string line)
{
  stack<char> parenStack;
  string result = "True";

  for (int i = 0; i < line.size(); ++i)
  {
    char c = line.at(i);
    result = compare(c, parenStack);
    if (result == "False")
      break;
  }
  return result;
}

string compare(char c, stack<char>& parenStack)
{
  char paren;
  if (c == '(')
    parenStack.push(')');
  else if (c == '[')
    parenStack.push(']');
  else if (c == '{')
    parenStack.push('}');
  else if (c == ')' || c == ']' || c == '}')
  {
    paren = parenStack.top();
    parenStack.pop();
    if (c != paren)
      return "False";
  }z
  return "True";
}
