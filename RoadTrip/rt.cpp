// Road Trip solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::remove;
using std::sort;
using std::string;
using std::vector;

vector<int> parseLine(string);
void printDistances(vector<int>);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      vector<int> distances = parseLine(line);
      printDistances(distances);
      cout << endl;
    }
    inputFile.close();
  }
  return 0;
}

vector<int> parseLine(string line)
{
  char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,;";

  for (int i = 0; i < strlen(chars); ++i)
    line.erase (remove(line.begin(), line.end(), chars[i]), line.end());

  istringstream iss(line);
  vector<string> tokens;
  copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter<vector<string> >(tokens));

  vector<int> numTokens;
  for(int i = 0; i < tokens.size(); ++i)
    numTokens.push_back(atoi(tokens[i].c_str()));

  sort(numTokens.begin(), numTokens.end());

  return numTokens;
}

void printDistances(vector<int> distances)
{
  int curPos = 0;
  for(int i = 0; i < distances.size() - 1; ++i)
  {
    cout << (distances[i] - curPos) << ",";
    curPos = distances[i];
  }
  cout << (distances[distances.size()- 1] - curPos);
}
