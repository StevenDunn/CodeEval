// Longest Repeated Substring solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::min;
using std::remove_if;
using std::sort;
using std::string;
using std::vector;

string printLRS(string);
string findLRS(string);
string lcp(string, string);

int main (int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      cout << printLRS(line) << endl;
    }
    inputFile.close();
  }

  return 0;
}

string printLRS(string line)
{
  string result = findLRS(line);
  if (result.empty())
    return "NONE";
  else 
    return result;
}

string findLRS(string line)
{
  int len = line.size();
  vector<string> suffixes(len);
  for (int i = 0; i < len; ++i)
    suffixes[i] = line.substr(i, len);

  sort(suffixes.begin(), suffixes.end());

  string lrs = "";
  for (int i = 0; i < len - 1; ++i)
  {
    string prefix = lcp(suffixes[i], suffixes[i+1]);
    if(prefix.size() > lrs.size())
      lrs = prefix;
  }

  lrs.erase(remove_if(lrs.begin(), lrs.end(), ::isspace), lrs.end());
  return lrs;
}

string lcp(string suffix1, string suffix2)
{
  int n = min(suffix1.size(), suffix2.size());
  for (int i = 0; i < n; ++i)
  {
    if (suffix1[i] != suffix2[i])
      return suffix1.substr(0, i);
  }

  if (suffix2.substr(n-1) == suffix1 )
    return suffix1.substr(0, n - 1);

  return suffix1.substr(0, n);
}
