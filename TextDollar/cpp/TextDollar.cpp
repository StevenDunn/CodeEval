// Text Dollar solution for CodeEval.com in C++ by Steven A. Dunn

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::string;
using std::to_string;

string getDollarName(string);
string getOnesWord(char);
string convertTens(char, char);
string tensWordTeens(char);
string getTensWord(string);
string getHundredsWord(string);
string getThousandsWord(string);
string getTenThousandsWord(string);
string getHundredThousandsWord(string);
string getMillionsWord(string);
string getTenMillionsWord(string);
string getHundredMillionsWord(string);

int main(int argc, char* argv[]) {
	ifstream inputFile(argv[1]);
	string line;

	if(inputFile)
	{
		while(getline(inputFile, line))
			cout << getDollarName(line) << endl;
		inputFile.close();
	}
	return 0;
}

string getDollarName(string line)
{
	long number = atol(line.c_str());
	string text = "";

	if (number < 100)
		text += getTensWord(line);
	else if (number < 1000)
		text += getHundredsWord(line);
	else if (number < 10000)
		text += getThousandsWord(line);
    else if (number < 100000)
        text += getTenThousandsWord(line);
    else if (number < 1000000)
        text += getHundredThousandsWord(line);
    else if (number < 10000000)
        text += getMillionsWord(line);
    else if (number < 100000000)
        text += getTenMillionsWord(line);
    else
        text += getHundredMillionsWord(line);

    text += "Dollars";

   	return text;
}

string getOnesWord(char digit)
{
	int val = digit - '0';
	switch(val)
	{
		case 1: return "One";
		case 2: return "Two";
		case 3: return "Three";
		case 4: return "Four";
		case 5: return "Five";
		case 6: return "Six";
		case 7: return "Seven";
		case 8: return "Eight";
		case 9: return "Nine";
		case 0: return "";
	}
	return "";
}

string convertTens(char firstDigit, char secondDigit)
{
	int val = firstDigit - '0';
	switch(val)
	{
		case 1: return tensWordTeens(secondDigit);
		case 2: return "Twenty";
		case 3: return "Thirty";
		case 4: return "Forty";
		case 5: return "Fifty";
		case 6: return "Sixty";
		case 7: return "Seventy";
		case 8: return "Eighty";
		case 9: return "Ninety";
		case 0: return "";
	}
	return "";
}

string tensWordTeens(char digit)
{
	int val = digit - '0';
	switch(val)
	{
		case 0: return "Ten";
		case 1: return "Eleven";
		case 2: return "Twelve";
		case 3: return "Thirteen";
		case 4: return "Fourteen";
		case 5: return "Fifteen";
		case 6: return "Sixteen";
		case 7: return "Seventeen";
		case 8: return "Eighteen";
		case 9: return "Nineteen";
	}
	return "";
}

string getTensWord(string text)
{
    int number = atoi(text.c_str());
    string result = "";

    if (number == 0)
        return result;
    else if (number < 10)
    {
        text = to_string(number);
        result += getOnesWord(text[0]);
    }
    else if (number < 20)
        result += convertTens(text[0], text[1]);
    else
    {
        result += convertTens(text[0], text[1]);
        string onesWord = getOnesWord(text[1]);
        if (onesWord != "")
            result += onesWord;
    }
    return result;
}

string getHundredsWord(string text)
{
	string result = getOnesWord(text[0]);
	string sub = getTensWord(text.substr(1, 2));
    if (result != "")
        return result + "Hundred" + sub;
    return sub;
}

string getThousandsWord(string text)
{
	string result = getOnesWord(text[0]);
	string sub = getHundredsWord(text.substr(1));
    if (result != "")
        return result + "Thousand" + sub;
    return sub;
}

string getTenThousandsWord(string text)
{
	string result = getTensWord(text.substr(0, 2));
	string sub = getHundredsWord(text.substr(2));
    if (result != "")
        return result + "Thousand" + sub;
    return sub;
}

string getHundredThousandsWord(string text)
{
	string result = getHundredsWord(text.substr(0, 4));
	string sub = getHundredsWord(text.substr(3));
    if (result != "")
        return result + "Thousand" + sub;
    return sub;
}

string getMillionsWord(string text)
{
	string result = getOnesWord(text[0]);
	string sub = getHundredThousandsWord(text.substr(1));

    if (result != "")
        return result + "Million" + sub;
    return sub;
}

string getTenMillionsWord(string text)
{
	string result = convertTens(text[0], text[1]);
	string sub = getHundredThousandsWord(text.substr(2));

    if (result != "")
        return result + "Million" + sub;
    return sub;
}

string getHundredMillionsWord(string text)
{
	string result = getHundredsWord(text.substr(0,4));
	string sub = getHundredThousandsWord(text.substr(3));

    if (result != "")
        return result + "Million" + sub;
    return sub;
}