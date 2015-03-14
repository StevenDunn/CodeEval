// Split the Number C++ soln for Code Eval by Steven A Dunn

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
using std::string;
using std::vector;

void split_the_number(string);
vector<string> parse(string);

int main(int argc, char* argv[])
{
    ifstream input_file(argv[1]);
    string line;

    if (input_file)
    {
        while (getline(input_file, line))
            split_the_number(line);
        input_file.close();
    }
    return 0;
}

void split_the_number(string line)
{
  vector<string> parsed_line = parse(line);
  string nums = parsed_line[0];
  string expr = parsed_line[1];

  int operator_index = expr.find("+");
  if (operator_index == string::npos)
    operator_index = expr.find("-");

  long num1 = atoi(nums.substr(0, operator_index).c_str());
  long num2 = atoi(nums.substr(operator_index).c_str());

  if (expr[operator_index] == '+')
    cout << (num1 + num2) << endl;
  else
    cout << (num1 - num2) << endl;
}

vector<string> parse(string input)
{
  istringstream iss(input);
  string line;
  vector<string> tokens;

  while(getline(iss, line, ' '))
    tokens.push_back(line);

  return tokens;
}