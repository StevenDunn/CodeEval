// Text Dollar solution for CodeEval.com in C++ by Steven A. Dunn

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::string;

string getDollarName(string);
string getWord(char, int);
string toWord(char);
string getPositionWord(int);
string getFinalWord(string);

int main(int argc, char* argv[]) {
	ifstream inputFile(argv[1]);
	string line;
	
	if(inputFile) 
	{
		while(getline(inputFile, line))
		{
			cout << getDollarName(line) << endl;
		}
		inputFile.close();
	}
}

string getDollarName(string numberStr)
{
	int length = numberStr.size();
	string nextWord;
	ostringstream oss("");
	
	for(int i = 0; i < length - 2; ++i)
	{
		char digit = numberStr.at(i);
		if(digit == '0')
			continue;
		nextWord = getWord(digit, length - i);
		oss << nextWord;
	}
	
	nextWord = getFinalWord(numberStr.substr(numberStr.size() - 1, 2));
	oss << nextWord;

	oss << "Dollars";
	return oss.str();
}

string getWord(char digit, int position)
{	
	string word = toWord(digit) + getPositionWord(position);
	//cout << "digit is: " << digit << endl;
	//cout << "word is: " << word << endl;
	return word;
}

string toWord(char digit)
{
	string result;
	switch(digit)
	{
		case '1': result = "One"; break;
		case '2': result = "Two"; break;
		case '3': result = "Three"; break;
		case '4': result = "Four"; break;
		case '5': result = "Five"; break;
		case '6': result = "Six"; break;
		case '7': result = "Seven"; break;
		case '8': result = "Eight"; break;
		case '9': result = "Nine"; break;
	}
	return result;
}

string getPositionWord(int position)
{
	string result;
	switch(position)
	{
		case 10:
		case 9:
		case 8:
		case 7:
		case 6:
		case 5:
		case 4:
		case 3:
		case 2: 
		case 1: 
		default: result = "";
	}
	return result;
}

string getFinalWord(string numberStr)
{
	ostringstream result("");
	if(numberStr.size() == 2) {}
	
	char lastDigit = numberStr.at(numberStr.size() - 1);
	// cout << "last digit: " << lastDigit << endl;
	result << toWord(lastDigit);
	
	return result.str();
}