// String List solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::sort;
using std::string;

void printPermutations(int, string);
string formatLetters(string);
void sortLetters(string&);
void removeDuplicates(string&);
void printLengthNPermutations(string, string, int);

// cheap hack because I don't feel the need to pass around an ostringstream to everything
// just for the sake of a coding challenge; I would do otherwise in production code
ostringstream resultOSS("");

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if(inputFile)
	{
		while(getline(inputFile, line))
		{
			int N = atoi(line.substr(0, line.find(",")).c_str());
			string letters = line.substr(line.find(",") + 1);
			
			printPermutations(N, letters);

		}
		inputFile.close();
	}
	
	return 0;
}

void printPermutations(int N, string letters)
{
	letters = formatLetters(letters);
	
	printLengthNPermutations("", letters, N);
	
	if(N == 0)
		cout << "" << endl;

  int pos = resultOSS.tellp();
  resultOSS.seekp(pos - 1);
  resultOSS << endl;

  cout << resultOSS.str();
  resultOSS.str("");
}

string formatLetters(string letters)
{
	sortLetters(letters);
	removeDuplicates(letters);
	return letters;
}

void sortLetters(string& letters)
{
	sort(letters.begin(), letters.end());
}

void removeDuplicates(string& letters)
{
	char oldChar = letters.at(0);
	char curChar = oldChar;
	
	ostringstream oss("");
	oss << oldChar;

	for(int i = 1; i < letters.size(); ++i)
	{
		curChar = letters.at(i);
		if(curChar != oldChar)
		{
			oss << curChar;
			oldChar = curChar;
		}
	}

	letters = oss.str();
}

void printLengthNPermutations(string currentString, string letters, int N)
{
  if (N == 0)
  {
    resultOSS << currentString << ",";
    return;
  }

  for(int i = 0; i < letters.size(); ++i)
  {
    string updatedString = currentString + letters[i];
    printLengthNPermutations(updatedString, letters, N - 1); 
  }
}
