// Ugly Numbers solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::string;
using std::vector;

long numUglies(string);
vector<string> add(string, vector<string>);
vector<string> subtract(string, vector<string>);
vector<string> concat(string, vector<string>);
string makeString(int);
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
      cout << numUglies(line) << endl; 
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
    vector<string> minuses = subtract(input.substr(i, 1), vals);
    vector<string> concats = concat(input.substr(i, 1), vals);

    vals = adds;
    vals.insert(vals.end(), minuses.begin(), minuses.end());
    vals.insert(vals.end(), concats.begin(), concats.end());

//    for(int i = 0; i < vals.size(); ++i)
//      cout << vals[i] << " ";
//    cout << endl;
  }

  for(int i = 0; i < vals.size(); ++i)
    if(isUgly(atoi(vals[i].c_str())))
        ++uglyCount;
  
  return uglyCount;
}

vector<string> add(string suffix, vector<string> vals)
{
  vector<string> updatedVals;

  int suffixNum = atoi(suffix.c_str());
  //cout << "suffix: " << suffix << endl;
  //cout << suffixNum << endl;
  for(int i = 0; i < vals.size(); ++i)
  {
    int n = atoi(vals[i].c_str());
    int updatedNum = n + suffixNum;
    string convertedNum = makeString(updatedNum); 
   
    updatedVals.push_back(convertedNum);
  }

//  for(int i = 0; i < updatedVals.size(); ++i)
//    cout << "updated vals: " << updatedVals[i] << endl;

  return updatedVals;
}

vector<string> subtract(string suffix, vector<string> vals)
{
  vector<string> updatedVals;

  int suffixNum = atoi(suffix.c_str());

  for(int i = 0; i < vals.size(); ++i)
  {
    int n = atoi(vals[i].c_str());
    int updatedNum = n - suffixNum;
    string convertedNum = makeString(updatedNum);

    updatedVals.push_back(convertedNum);
  }

//  for(int i = 0; i < updatedVals.size(); ++i)
//    cout << "updated vals: " << updatedVals[i] << endl;

  return updatedVals;
}

vector<string> concat(string suffix, vector<string> vals)
{
  vector<string> updatedVals;

  for(int i = 0; i < vals.size(); ++i)
  {
    string concatVal = vals[i] + suffix;
    updatedVals.push_back(concatVal);
  }

  return updatedVals;
}

string makeString(int n)
{
  stringstream ss("");
  ss << n;
  
  string output;
  ss >> output;

  return output;
}

bool isUgly(int n)
{
  cout << n << " ";
  if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
    return true;
  return false;
}
