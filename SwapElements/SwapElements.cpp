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
vector<string> getTokens(string line);
vector<string> getSwapTokens(string);
vector<int> applySwaps(vector<int>, vector<string>);
void printList(vector<int>);

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
      vector<string> swapTokens = getSwapTokens(swaps);

      vector<int> swappedList = applySwaps(elemVec, swapTokens);
      
      printList(swappedList);
    }
    inputFile.close();
  }
}

vector<int> parseElements(string elements)
{
   vector<string> tokens = getTokens(elements);
   vector<int> tokensAsNum;
   for(int i = 0; i < tokens.size(); ++i)
     tokensAsNum.push_back(atoi(tokens.at(i).c_str()));

   return tokensAsNum;
}

vector<string> getTokens(string line)
{
  vector<string> tokens;
  istringstream iss(line);
  copy(
    istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));

  return tokens;
}

vector<string> getSwapTokens(string swaps)
{
  vector<string> tokens = getTokens(swaps);
 
  for(int i = 0; i < tokens.size(); ++i)
  {
    string token = tokens.at(i);
    if(token.at(token.size()-1) == ',')
    {
      token = token.substr(0, token.size() - 1);
      tokens.at(i) = token;
    }
  }

  return tokens;
}

vector<int> applySwaps(vector<int> elements, vector<string> swaps)
{
  for(int i = 0; i < swaps.size(); ++i)
  {
    string token = swaps.at(i);
    int elem1 = atoi(token.substr(0, token.find("-")).c_str());
    int elem2 = atoi(token.substr(token.find("-") + 1).c_str());

    int temp = elements.at(elem1);
    elements.at(elem1) = elements.at(elem2);
    elements.at(elem2) = temp;
  }

  return elements;
} 

void printList(vector<int> list)
{
  for(int i = 0; i < list.size(); ++i)
    cout << list.at(i) << " ";
  cout << endl;
}
