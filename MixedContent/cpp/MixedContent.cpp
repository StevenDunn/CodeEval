// Mixed Content solution in C++ for CodeEval.com by Steven A. Dunn

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
using std::ostringstream;
using std::replace;
using std::string;
using std::vector;

vector<string> words;
vector<int> nums;

string getFormattedLine(string);
bool isWord(string);
bool isDigit(char);
string format(vector<string>, vector<int>);

int main (int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      cout << getFormattedLine(line) << endl;

      words.clear();
      nums.clear();
    }
    inputFile.close();
  }
  return 0;
}

string getFormattedLine(string line)
{
  replace(line.begin(), line.end(), ',', ' ');

  istringstream iss(line);
  string token;
  while (iss >> token)
  {
    if( isWord(token) )
      words.push_back(token);
    else
      nums.push_back(atoi(token.c_str()));
  }

  string result = format(words, nums); 

  return result;
}

bool isWord(string token)
{
  for(int i = 0; i < token.size(); ++i)
    if (!isDigit(token[i]))
      return true;
  return false;
}

bool isDigit(char c)
{
  int x = c - '0';
  if (x >= 0 && x <= 9)
    return true;
  return false;
}

string format(vector<string> words, vector<int> nums)
{
  ostringstream oss("");
  bool wordsEmpty = words.empty();
  bool numsEmpty = nums.empty();
  if (!wordsEmpty)
  {
    for(int i = 0; i < words.size() - 1; ++i)
      oss << words[i] << ",";
    oss << words[words.size() - 1];
  }

  if(!wordsEmpty && !numsEmpty)
    oss << "|";

  if(!numsEmpty)
  {
    for(int i = 0; i < nums.size() - 1; ++i)
      oss << nums[i] << ",";
    oss << nums[nums.size() - 1];
  }
  return oss.str();
}
