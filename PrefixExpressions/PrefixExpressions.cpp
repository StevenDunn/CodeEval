// Prefix Expressions solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;

int evaluate(string&);
vector<string> parseExpression(string);
bool isOperator(string);
int eval(string, string, string);
void updateExpression(vector<string>&, int, int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
      cout << evaluate(line) << endl;

    inputFile.close();
  }
  return 0;
}

int evaluate(string& expression)
{
  vector<string> tokens = parseExpression(expression);
  int result;

  for (int i = tokens.size() - 1; i >= 0; --i)
  {
    if (isOperator(tokens[i]))
    {
      result = eval(tokens[i], tokens[i+1], tokens[i+2]);
      updateExpression(tokens, result, i);
    }
  }
  return result;
}

vector<string> parseExpression(string expression)
{
  vector<string> result;
  string s;
  istringstream iss(expression);
  while (iss >> s)
    result.push_back(s);
  return result;
}

bool isOperator(string opr)
{
  if (opr == "+" || opr == "-" || opr == "*" || opr == "/")
    return true;
  return false;
}

int eval(string opr, string opnd1, string opnd2)
{
  int x = atoi(opnd1.c_str());
  int y = atoi(opnd2.c_str());

  if (opr == "+")
    return x + y;
  if (opr == "-")
    return x - y;
  if (opr == "*")
    return x * y;
  if (opr == "/")
    return x / y;
  else 
    return 0;
}

void updateExpression(vector<string>& expression, int result, int i)
{
  vector<string> updatedExpression;
  updatedExpression.assign(expression.begin(), expression.begin() + i);

  ostringstream oss("");
  oss << result;
  updatedExpression.push_back(oss.str());

  for(int j = i + 3; j < expression.size(); ++j)
    updatedExpression.push_back(expression[j]);

  expression = updatedExpression;
}
