// Word to Digit solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int createDigit(string);

int main (int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<string> words;
			size_t semicolonPos = line.find(";");
			
			while (semicolonPos != string::npos)
			{				
				words.push_back(line.substr(0, semicolonPos));
				line = line.substr(semicolonPos + 1);
				semicolonPos = line.find(";");
			}
			words.push_back(line);
			
			for (int i = 0; i < words.size(); i++) 
			{
				cout << createDigit(words[i]);
			}
			cout << endl;
		}
	}
}

int createDigit(string s)
{
	int result = 0;
	if (s == "one") { result = 1; }
	if (s == "two") { result = 2; }
	if (s == "three") { result = 3; }
	if (s == "four") { result = 4; }
	if (s == "five") { result = 5; }
	if (s == "six") { result = 6; }
	if (s == "seven") { result = 7; }
	if (s == "eight") { result = 8; }
	if (s == "nine") { result = 9; }
	return result;
}
