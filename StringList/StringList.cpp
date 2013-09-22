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

string printPermutations(int, string);
string formatLetters(string);
void sortLetters(string&);
void removeDuplicates(string&);

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
			
			cout << printPermutations(N, letters) << endl;
		}
		inputFile.close();
	}
	
	return 0;
}

string printPermutations(int N, string letters)
{
	letters = formatLetters(letters);
	return letters;
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