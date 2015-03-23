// Flavius Jospehus solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

vector<int> flavius(int, int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      int commaPos = line.find(",");
      int N = atoi(line.substr(0, commaPos).c_str());
      int M = atoi(line.substr(commaPos + 1).c_str());
      vector<int> flaviusSeq = flavius(N, M);
      for (int i = 0; i < flaviusSeq.size(); ++i)
        cout << flaviusSeq[i] << " ";
      cout << endl;
    }
    inputFile.close();
  }
  return 0;
}

vector<int> flavius(int N, int M)
{
  vector<int> visited(N,0);
  int elementsVisited = 0; 
  vector<int> results;
  int stepCount = 0;

  for (int i = 0; i <= N; ++i) 
  {
    if (i == N)
    {
      i = -1;
      continue;
    }

    if(visited[i] == 1)
      continue;

    if (stepCount != M - 1)
    {
      ++stepCount;
      continue;
    }

    if(visited[i] == 0)
    {
      visited[i] = 1;
      ++elementsVisited;
      results.push_back(i);
      if (elementsVisited == N)
        break;

      stepCount = 0;
      continue;
    }
  }
  return results;
}
