// Swap Elements solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
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
using std::string;
using std::vector;

vector<int> parseElements(string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      string elements = line.substr(0, line.find(":"));
      vector<int> elemVec = parseElements(elements);

      string swaps = line.substr(line.find(":") + 1);
      cout << swaps << endl; 
    }
    inputFile.close();
  }
}

vector<int> parseElements(string elements)
{
  vector<string> tokens;
  istringstream iss(elements);
  copy(
    istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));

   vector<int> tokensAsNum;
   for(int i = 0; i < tokens.size(); ++i)
     tokensAsNum.push_back(atoi(tokens.at(i).c_str()));

   return tokensAsNum;
}
