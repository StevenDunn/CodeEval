// Spiral Printing solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using std::back_inserter;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::replace;
using std::string;
using std::vector;

vector<string> parseLine(string);
void spiralPrint(int, int, vector<string>);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      vector<string> nums = parseLine(line);
      int N = atoi(nums[0].c_str());
      int M = atoi(nums[1].c_str());
      nums.erase(nums.begin(), nums.begin() + 2);

      spiralPrint(N, M, nums);
    }
    inputFile.close();
  }
  return 0;
}

vector<string> parseLine(string line)
{
  replace(line.begin(), line.end(), ';', ' ');

  istringstream iss(line);
  vector<string> tokens;
  copy(
    istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));

  return tokens;
}

void spiralPrint(int N, int M, vector<string> vals)
{
  int cur = 0;
  int size = N * M;
  int nStep = M;
  int visited = 0;
  while(true)
  {
    for(int i = 0; i < M; ++i)
    {
      cout << vals[cur] << " ";
      ++cur;
      ++visited;
    }
    if(visited == size)
      break;
    --cur; 
    for(int j = 0; j < N - 1; ++j)
    {
      cur += nStep;
      ++visited;
      cout << vals[cur] << " ";
    }
    if(visited == size)
      break;
    for(int i = 0; i < M - 1; ++i)
    {
      --cur;
      ++visited;
      cout << vals[cur] << " ";
    }
    if(visited == size)
      break;
    for(int j = 0; j < N - 2; j++)
    {
      cur -= nStep; 
      ++visited;
      cout << vals[cur] << " ";
    }
    if(visited == size)
      break;
    ++cur;

    N = N - 2;
    M = M - 2;
  }

  cout << endl;
}
