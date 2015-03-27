// Pass Triangle solution in C++ for CodeEval.com by Steven A. Dunn

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::stack;
using std::string;
using std::vector;

void calculateSum(string, vector<long>&);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    stack<string> lineStack;
    while (getline(inputFile, line))
      lineStack.push(line);

    vector<long> sums; 
    while (!lineStack.empty())
    {
      string line = lineStack.top();
      calculateSum(line, sums);
      lineStack.pop();
    }

    cout << sums[0] << endl;

    inputFile.close();
  }
  return 0;
}

void calculateSum(string line, vector<long>& runningSums)
{
  vector<long> lineNumbers;
  istringstream iss(line);
  string s;
  while (iss >> s)
    lineNumbers.push_back(atol(s.c_str()));

  if (runningSums.size() == 0)
  {
    runningSums = lineNumbers;
    return;
  }

  vector<long> newSums;
  for (int i = 0; i < runningSums.size() - 1; ++i)
  {
    long maxNum = 0;
    runningSums[i] > runningSums[i + 1] ? maxNum = runningSums[i] : maxNum = runningSums[i + 1];   
    newSums.push_back(maxNum + lineNumbers[i]);
  }

  runningSums = newSums;  
  return;
}

