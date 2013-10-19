// Morse Code solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
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
using std::map;
using std::ostringstream;
using std::string;
using std::vector;

map<string, char> morseDict;

void initDict();
string getMorseLine(string);
string getMorseWord(string);
vector<string> tokenize(string);
char getMorseChar(string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    initDict();
    while(getline(inputFile, line))
      cout << getMorseLine(line) << endl;
    
    inputFile.close();
  }

  return 0;
}

void initDict()
{
  morseDict[".-"] = 'A';
  morseDict["-..."] = 'B';
  morseDict["-.-."] = 'C';
  morseDict["-.."] = 'D';
  morseDict["."] = 'E';
  morseDict["..-."] = 'F';
  morseDict["--."] = 'G';
  morseDict["...."] = 'H';
  morseDict[".."] = 'I';
  morseDict[".---"] = 'J';
  morseDict["-.-"] = 'K';
  morseDict[".-.."] = 'L';
  morseDict["--"] = 'M';
  morseDict["-."] = 'N';
  morseDict["---"] = 'O';
  morseDict[".--."] = 'P';
  morseDict["--.-"] = 'Q';
  morseDict[".-."] = 'R';
  morseDict["..."] = 'S';  
  morseDict["-"] = 'T';
  morseDict["..-"] = 'U';
  morseDict["...-"] = 'V';
  morseDict[".--"] = 'W';
  morseDict["-..-"] = 'X';
  morseDict["-.--"] = 'Y';
  morseDict["--.."] = 'Z';

  morseDict[".----"] = '1';
  morseDict["..---"] = '2';
  morseDict["...--"] = '3';
  morseDict["....-"] = '4';
  morseDict["....."] = '5';
  morseDict["-...."] = '6';
  morseDict["--..."] = '7';
  morseDict["---.."] = '8';
  morseDict["----."] = '9';
  morseDict["-----"] = '0';
}

string getMorseLine(string line)
{
  vector<string> words;
  int wordBreak = line.find("  ");

  while(wordBreak != string::npos)
  {  
    words.push_back(line.substr(0, wordBreak));
    line = line.substr(wordBreak + 1); 
    wordBreak = line.find("  ");
  }
  words.push_back(line);

  ostringstream translatedLine("");
  for(int i = 0; i < words.size(); ++i)
    translatedLine << getMorseWord(words[i]) << " ";

  return translatedLine.str();
}

string getMorseWord(string line)
{
  vector<string> words = tokenize(line);

  ostringstream oss("");
  for(int i = 0; i < words.size(); ++i)
    oss << getMorseChar(words[i]);
  
  return oss.str();
}

vector<string> tokenize(string line)
{
  istringstream iss(line);
  vector<string> tokens;

  copy(
    istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter<vector<string> >(tokens));  

  return tokens;
}

char getMorseChar(string word)
{
  return morseDict[word];
}
