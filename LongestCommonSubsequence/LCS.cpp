// LCS solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::max;
using std::string;
using std::vector;

string LCS(string, string);
string backtrack(vector<vector<int> >, string, string, int, int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      if(line == "")
        continue;

      int semicolPos = line.find(";");
      string X = line.substr(0, semicolPos);
      string Y = line.substr(semicolPos + 1);

      cout << LCS(X, Y) << endl;
    }
    inputFile.close();
  }

  return 0;
}

string LCS(string X, string Y)
{
  int m = X.size();
  int n = Y.size();
  vector<vector<int> > C(m+1, vector<int>(n+1));

  for(int i = 0; i <= m; ++i)
  {
    for(int j = 0; j <= n; ++j)
    {
      if (i == 0 || j == 0)
        C[i][j] = 0;
      else if (X[i-1] == Y[j-1])
        C[i][j] = C[i-1][j-1] + 1;
      else
        C[i][j] = max(C[i-1][j], C[i][j-1]);
    }
  }

  return backtrack(C, X, Y, m, n);
}

string backtrack(vector<vector<int> > C, string X, string Y, int i, int j)
{
  if (i == 0 || j == 0)
    return "";
  else if (X[i-1] == Y[j-1])
    return backtrack(C, X, Y, i-1, j-1) + X[i-1];
  else if (C[i][j-1] > C[i-1][j])
    return backtrack(C, X, Y, i, j-1);
  else
    return backtrack(C, X, Y, i-1, j);
}
