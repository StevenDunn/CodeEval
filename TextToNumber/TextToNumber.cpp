// Text to Number solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

long textToNumber(string);
bool isDigit(string, long&);
bool isMagnitude(string, long&);
bool isNegative(string);

bool negative = false;

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      cout << textToNumber(line) << endl;
    }
    inputFile.close();
  }

  return 0;
}

long textToNumber(string line)
{
  long result = 0;
  long subResult = 0;
  long convertedValue = 0;
  negative = false;

  stringstream ss(line);
  string word;
  

  while(ss >> word)
  {
    if(isDigit(word, convertedValue))
      subResult += convertedValue;

    else if(isMagnitude(word, convertedValue))
    {
      subResult *= convertedValue;
      result += subResult;
      subResult = 0;
    }

    else if (isNegative(word))
      negative = true;
  }

  if(subResult != 0)
    result += subResult;

  if(negative)
    result *= -1;

  return result;
}

bool isDigit(string word, long& convertedValue)
{
  bool result = true;
  if (word == "one")
    convertedValue = 1;
  else if (word == "two")
    convertedValue = 2;
  else if (word == "three")
    convertedValue = 3;
  else if (word == "four")
    convertedValue = 4;
  else if (word == "five")
    convertedValue = 5;
  else if (word == "six")
    convertedValue = 6;
  else if (word == "seven")
    convertedValue = 7;
  else if (word == "eight")
    convertedValue = 8;
  else if (word == "nine")
    convertedValue = 9;
  else if (word == "ten")
    convertedValue = 10;
  else if (word == "eleven")
    convertedValue = 11;
  else if (word == "twelve")
    convertedValue = 12;
  else if (word == "thirteen")
    convertedValue = 13;
  else if (word == "fourteen")
    convertedValue = 14;
  else if (word == "fifteen")
    convertedValue = 15;
  else if (word == "sixteen")
    convertedValue = 16;
  else if (word == "seventeen")
    convertedValue = 17;
  else if (word == "eighteen")
    convertedValue = 18;
  else if (word == "nineteen")
    convertedValue = 19;
  else if (word == "twenty")
    convertedValue = 20;
  else if (word == "thirty")
    convertedValue = 30;
  else if (word == "forty")
    convertedValue = 40;
  else if (word == "fifty")
    convertedValue = 50;
  else if (word == "sixty")
    convertedValue = 60;
  else if (word == "seventy")
    convertedValue = 70;
  else if (word == "eighty")
    convertedValue = 80;
  else if (word == "ninety")
    convertedValue = 90;
  else 
    result = false;

  return result;
}

bool isMagnitude(string word, long& convertedValue) 
{
  bool result = true;
  if (word == "hundred")
    convertedValue = 100;
  else if (word == "thousand")
    convertedValue = 1000;
  else if (word == "million")
    convertedValue = 1000000;
  else
    result = false;

  return result;
}

bool isNegative(string word) 
{
  if (word == "negative")
    negative = true;
  return negative;
}
