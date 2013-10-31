// Ugly Numbers solution in C++ for CodeEval.com by Steven A. Dunn

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

long numUglies(string);
vector<string> add(string, vector<string>);
bool isUgly(int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      cout << line << endl;
      cout << "num uglies: " << numUglies(line) << endl;
      cout << endl;
    }
    inputFile.close();
  }
  return 0;
}

long numUglies(string input)
{
  long uglyCount = 0;
  vector<string> vals;

  vals.push_back(input.substr(0, 1));

  for(int i = 1; i < input.size(); ++i)
  {
    vector<string> adds = add(input.substr(i, 1), vals);
    //vector<string> minuses = subtract(input.substr(i, 1), vals);
    //vector<string> concats = concat(input.substr(i, 1), vals);

    vals = adds;
    //vals.insert(vals.end(), minuses.start(), minuses.end());
    //vals.insert(vals.end(), concats.start(), concats.end());
  }

  for(int i = 0; i < vals.size(); ++i)
    if(isUgly(atoi(vals[i].c_str())))
        ++uglyCount;

  return uglyCount;
}

vector<string> add(string prefix, vector<string> vals)
{
  vector<string> updatedVals;

  int prefixNum = atoi(prefix.c_str());
  cout << prefixNum << endl;
  for(int i = 0; i < vals.size(); ++i)
  {
    
  }

  return updatedVals;
}

bool isUgly(int n)
{
  if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
    return true;
  return false;
}
