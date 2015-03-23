// Reverse Groups solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
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
vector<int> reverseGroups(vector<int>, int);
 
int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      int semicolonPos = line.find(";");
      vector<int> seq  = parseLine(line.substr(0, semicolonPos));
      int K = atoi(line.substr(semicolonPos + 1).c_str());
      vector<int> result = reverseGroups(seq, K); 
      for(int i = 0; i < result.size() - 1; ++i)
        cout << result[i] << ",";
      cout << result[result.size() - 1] << endl;
    }
    inputFile.close();
  }
  return 0;
}

vector<int> parseLine(string line)
{
  replace(line.begin(), line.end(), ',', ' ');
  vector<int> result;
  istringstream iss(line);
  string s;
  while (iss >> s)
    result.push_back(atoi(s.c_str()));
  return result;
}

vector<int> reverseGroups(vector<int> seq, int K)
{
  vector<int> reversedSeq;
  for(int i = 0; i < seq.size(); i = i + K)
    if (i + K <= seq.size())
      for(int j = i + K - 1; j >= i; --j)
        reversedSeq.push_back(seq[j]);

  if (seq.size() % K != 0)
    for(int i = seq.size() - K + 1; i < seq.size(); ++i)
      reversedSeq.push_back(seq[i]);

  return reversedSeq;
}
