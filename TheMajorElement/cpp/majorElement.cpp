// Major Element solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::back_inserter;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::map;
using std::ostringstream;
using std::pair;
using std::replace;
using std::string;
using std::vector;

string getMajorElement(string);
vector<string> tokenizeString(string);
int findMajorElement(vector<int>);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
      cout << getMajorElement(line) << endl;  
    inputFile.close();
  }
}

string getMajorElement(string line)
{
  replace(line.begin(), line.end(), ',', ' ');

  vector<string> tokens = tokenizeString(line);
  vector<int> converted_tokens;
  for(int i = 0; i < tokens.size(); ++i)
    converted_tokens.push_back(atoi(tokens[i].c_str()));

  int majorElement = findMajorElement(converted_tokens);

  string result = "";
  if (majorElement == -1)
    result = "None";
  else
  {
    ostringstream oss;
    oss << majorElement;
    result = oss.str();
  }
  return result;
}

vector<string> tokenizeString(string line)
{
  vector<string> tokens;
  istringstream iss(line);
  copy(
    istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));
  return tokens;
}

int findMajorElement(vector<int> items)
{
  int L = items.size();
  map<int, int> counts;

  for (int i = 0; i < L; ++i)
  {
    if (counts.find(items[i]) != counts.end())
      counts[items[i]] = counts[items[i]] + 1;
    else
      counts.insert(pair<int, int>(items[i], 1));
  }

  int result = -1;
  for (map<int,int>::iterator it = counts.begin(); it != counts.end(); ++it)
  {
    if (it->second > L/2)
    {
      result = it->first;
      break;
    }
  }
  return result;
}
