// Find Min solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <climits>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::sort;
using std::string;
using std::vector;

vector<int> tokenize(string);
vector<int> findKnownValues(int, int, int, int, int);
int nextMin(vector<int>);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;
  
  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      vector<int> params = tokenize(line);
      int N = params[0];
      int K = params[1];
      int A = params[2];
      int B = params[3];
      int C = params[4];
      int R = params[5];

      vector<int> knownValues = findKnownValues(K, A, B, C, R);
      sort(knownValues.begin(), knownValues.end());


      for(int i = K; i <= N; ++i)
      {
        int nextVal = nextMin(knownValues);
        knownValues.insert(knownValues.begin() + nextVal, nextVal);

        if(i == N)
          cout << nextVal << endl;
      }
    }
    inputFile.close();
  }

  return 0;
}

vector<int> tokenize(string line)
{
  vector<int> tokens;
  int commaPos = line.find(",");
  
  while(commaPos != string::npos)
  {
    int N = atoi(line.substr(0, commaPos).c_str());
    tokens.push_back(N);
    line = line.substr(commaPos + 1);
    commaPos = line.find(",");
  }
  tokens.push_back(atoi(line.c_str()));

  return tokens;
}

vector<int> findKnownValues(int K, int A, int B, int C, int R)
{
  vector<int> knownValues;
  knownValues.push_back(A);

  for(int i = 1; i < K; ++i)
  {
    int m = (B * knownValues[i-1] + C) % R;
    knownValues.push_back(m);
  }
  return knownValues;
}

int nextMin(vector<int> values)
{
  int min = 0;
  for(int i = 0; i < values.size(); ++i)
  {
    if(values[i] != i)
     min = i; 
  }

  return min;
}
