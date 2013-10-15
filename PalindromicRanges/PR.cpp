// Palindromic Range solution in C++ for CodeEval.com by Steven A. Dunn

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
using std::ostringstream;
using std::reverse;
using std::string;
using std::vector;

int numRanges(string);
bool isPalindrome(int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      int rangeCount = numRanges(line);
      cout << rangeCount << endl;
    }
    inputFile.close();
  }

  return 0;
}

int numRanges(string rangeStr)
{
  int x = atoi(rangeStr.substr(0, rangeStr.find(" ")).c_str());
  int y = atoi(rangeStr.substr(rangeStr.find(" ")).c_str());

  int interestingRangeCount = 0;
 
  vector<int> nums;
  for(int i = x; i <= y; ++i)
  {
    if(isPalindrome(i))
      nums.push_back(1);
    else
      nums.push_back(0);
  }

  for(int i = 0; i < nums.size(); ++i)
  {
    int palindromeCount = 0;
    for(int j = i; j < nums.size(); ++j)
    {
      if(nums[j] == 1)
         ++palindromeCount;

      if(palindromeCount % 2 == 0)
        ++interestingRangeCount;
    }
  }

  return interestingRangeCount;
}

bool isPalindrome(int x)
{
  string word;
  ostringstream oss;
  oss << x;
  word = oss.str();
  
  string reverseWord = word;
  reverse(reverseWord.begin(), reverseWord.end());

  if (word == reverseWord)
    return true;

  return false;
}
