// Sudoku solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cmath>
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
using std::replace;
using std::string;
using std::vector;

vector<int> parseLine(string);
string isValid(int, vector<int>);
bool rowCheck(int, vector<int>);
bool colCheck(int, vector<int>);
bool gridCheck(int, vector<int>);
int getSumForCheck(int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      int N = line.at(0) - '0';
      vector<int> nums = parseLine(line);
      cout << isValid(N, nums) << endl;
    }
    inputFile.close();
  }
  return 0;
}

vector<int> parseLine(string line)
{
  vector<int> results;
  line = line.substr(line.find(";") + 1);
  replace(line.begin(), line.end(), ',', ' ');
  istringstream iss(line);
  string s;
  while (iss >> s)
    results.push_back(atoi(s.c_str()));
  return results;
}

string isValid(int N, vector<int> nums)
{
  if (rowCheck(N, nums) && colCheck(N, nums) && gridCheck(N, nums))
    return "True";
  return "False";  
}

bool rowCheck(int N, vector<int> nums)
{ 
  int sumForCheck = getSumForCheck(N);

  for (int i = 0; i < N * N; i += N)
  {
    int rowSum = 0;
    for (int j = 0; j < N; ++j)
      rowSum += nums[i + j];

    if (rowSum != sumForCheck)
      return false;
  }
  return true;
}

bool colCheck(int N, vector<int> nums)
{
  int sumForCheck = getSumForCheck(N);

  for (int i = 0; i < N; ++i)
  {
    int colSum = 0;
    for (int j = 0; j < N * N; j += N)
      colSum += nums[i + j];
  
    if (colSum != sumForCheck)
      return false;
  }

  return true;
}

bool gridCheck(int N, vector<int> nums)
{
  int sumForCheck = getSumForCheck(N);
  int sqrtN = sqrt(N);
  for (int gridX = 0; gridX < sqrtN; ++gridX) 
  {
    for (int gridY = 0; gridY < sqrtN; ++gridY)
    {
      int gridSum = 0;
      for (int i = 0; i < sqrtN; ++i)
        for (int j = 0; j < sqrtN; ++j)
          gridSum += nums[N * i + j + gridY * (N * sqrtN) + gridX * (sqrtN)];
      if (gridSum != sumForCheck)
        return false;
    }
  }
  
  return true;
}

int getSumForCheck(int N)
{
  int result;
  if (N == 4)
    result = 4 + 3 + 2 + 1;
  else
    result = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1;
  return result;
}
