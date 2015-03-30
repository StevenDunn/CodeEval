// Chain Inspection solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::string;
using std::map;
using std::pair;
using std::replace;
using std::vector;

#define BEGIN 0
#define END -1

vector<string> parseLine(string);
vector<int> parseEntry(string);
vector<string> tokenize(string);
bool isChainValid(map<int, pair<int, int> >);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      vector<string> entries = parseLine(line);  
      map<int, pair<int, int> > chain;

      for(int entry = 0; entry < entries.size(); ++entry)
      {
        vector<int> startAndEnd = parseEntry(entries[entry]);
        int start = startAndEnd[0];
        int end = startAndEnd[1];

        chain[start] = {end, 0};
      }      
      bool result = isChainValid(chain);
      if(result) { cout << "GOOD" << endl; }
      else { cout << "BAD" << endl; }
    }
    inputFile.close();
  }
  return 0;
}

vector<string> parseLine(string line)
{
  replace(line.begin(), line.end(), ';', ' ');
  vector<string> tokens = tokenize(line);
  return tokens;
 }

vector<int> parseEntry(string entry)
{
  replace(entry.begin(), entry.end(), '-', ' ');
  vector<string> tokens = tokenize(entry);

  vector<int> entries;
  for(int i = 0; i < tokens.size(); ++i)
  {
    if(tokens[i] == "BEGIN")
      entries.push_back(BEGIN);
    else if(tokens[i] == "END")
      entries.push_back(END);
    else
      entries.push_back(atoi(tokens[i].c_str()));
  }
  return entries;
}

vector<string> tokenize(string line)
{
  vector<string> tokens;
  istringstream iss(line);

  copy(istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));

  return tokens;
}

bool isChainValid(map<int, pair<int, int> > chain)
{
  int element = chain[0].first;
  chain[0].second = 1;

  while(element != END)
  {
    if(chain[element].second == 1) { return false; }
    chain[element].second = 1;
    element = chain[element].first;
  }

  for(map<int, pair<int, int> >::iterator it = chain.begin(); it != chain.end(); ++it)
    if(it->second.second == 0) { return false; }
  return true;
}
