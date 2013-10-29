// Spiral Printing solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
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

vector<int> parseLine(string);
void spiralPrint(int, int, vector<int>);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      vector<int> nums = parseLine(line);
      int N = nums[0];
      int M = nums[1];
      nums.erase(nums.begin(), nums.begin() + 2);

      spiralPrint(N, M, nums);
    }
    inputFile.close();
  }
  return 0;
}

vector<int> parseLine(string line)
{
  replace(line.begin(), line.end(), ';', ' ');

  istringstream iss(line);
  vector<string> tokens;
  copy(
    istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));

  vector<int> nums;
  for(int i = 0; i < tokens.size(); ++i)
    nums.push_back(atoi(tokens[i].c_str()));

  return nums;
}

void spiralPrint(int N, int M, vector<int> vals)
{
  int cur = 0;
  //int startOffset = M + 1;
  //int originalM = M;
  //int originalN = N;

/*
  while(N > 1 && M > 1)
  {
    int topRight = start + M - 1;
    for(int i = start; i <= topRight; ++i)
      cout << vals[i] << " ";
    for(int j = topRight + originalM; j <= originalM * originalN - start; j = j + originalM)
     cout << vals[j] << " "; 
    for(int i = originalM * originalN - start - 2; i > ; --i)
      cout << vals[i] << " ";
    start += startOffset;
    N = N - 2;
    M = M - 2;
  } 
*/

  int size = N * M;
  int nStep = M;
  while(N > 1 && M > 1)
  {
    for(int i = 0; i < M; ++i)
    {
      cout << vals[cur] << " ";
      ++cur;
    }
    --cur; 
    for(int j = 0; j < N - 1; ++j)
    {
      cur += nStep;
      cout << vals[cur] << " ";
    }
    for(int i = 0; i < M - 1; ++i)
    {
      --cur;
      cout << vals[cur] << " ";
    }
    for(int j = 0; j < N - 2; j++)
    {
      cur -= nStep; 
      cout << vals[cur] << " ";
    }
    ++cur;

    N = N - 2;
    M = M - 2;
  }

  if(N == M && size % 2 != 0)
    cout << vals[cur];

  cout << endl;
    
}
