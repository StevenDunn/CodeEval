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
	
	if(length == 1)
		nextWord = getFinalWord(numberStr.substr(0, 1));
	else
		nextWord = getFinalWord(numberStr.substr(length - 2, 2));
		
	oss << nextWord;

	oss << "Dollars";
	return oss.str();
}

string getWord(char digit, int position)
{	
	string word = toWord(digit) + getPositionWord(position);
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
		case 10: result = "Billion"; break;
		case 9: result = "HundredMillion"; break;
		case 8: result = "TenMillion"; break;
		case 7: result = "Million"; break;
		case 6: result = "HundredThousand"; break;
		case 5: result = "TenThousand"; break;
		case 4: result = "Thousand"; break;
		case 3: result = "Hundred"; break;
		case 2: 
		case 1:
		default: result = "";
	}
	return result;
}

string getFinalWord(string numberStr)
{
	ostringstream oss("");
	
	char firstDigit = numberStr.at(0);
	char lastDigit = numberStr.at(numberStr.size() - 1);
	
	// cout << numberStr << endl;
	// 	cout << firstDigit << endl;
	// 	cout << lastDigit << endl;
	
	if(numberStr.size() == 2) 
	{
		switch(firstDigit)
		{
			case '9': oss << "Ninety"; break;
			case '8': oss << "Eighty"; break;
			case '7': oss << "Seventy"; break;
			case '6': oss << "Sixty"; break;
			case '5': oss << "Fifty"; break;
			case '4': oss << "Forty"; break;
			case '3': oss << "Thirty"; break;
			case '2': oss << "Twenty"; break;
			case '1': 
				{
					switch(lastDigit)
					{
						case '0': oss << "Ten"; break;
						case '1': oss << "Eleven"; break;
						case '2': oss << "Twelve"; break;
						case '3': oss << "Thirteen"; break;
						case '4': oss << "Fourteen"; break;
						case '5': oss << "Fifteen"; break;
						case '6': oss << "Sixteen"; break;
						case '7': oss << "Seventeen"; break;
						case '8': oss << "Eighteen"; break;
						case '9': oss << "Nineteen"; break;
					}
				}
		}
	}
	if(numberStr.size() != 2 || firstDigit != 1)
	{
		oss << toWord(lastDigit);
	}
	
	//cout << "last digit: " << lastDigit << endl;
	//cout << numberStr.size() << endl;

	
	return oss.str();
}