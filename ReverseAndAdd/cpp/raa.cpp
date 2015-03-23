// Reverse and Add Solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::string;

int reverse(int);
bool isPalindrome(int);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			int N = atoi(line.c_str());
			int reverseN = 0;
			for (int iterations = 0; iterations < 100; ++iterations)
			{
				reverseN = reverse(N);
				N += reverseN;
				if (isPalindrome(N))
				{
					cout << (iterations + 1) << " " << N << endl;
					break;
				}
			}
		}
		inputFile.close();
	}
	
	return 0;
}

int reverse(int n)
{
	ostringstream oss;
	oss << n;
	string word = oss.str();
	ostringstream reverse;
	for (int i = word.size() - 1; i >= 0; --i)
		reverse << word.at(i);
	int result = atoi(reverse.str().c_str());
	return result;
}

bool isPalindrome(int n)
{
	ostringstream oss;
	oss << n;
	string word = oss.str();
	for (int i = 0; i < word.size()/2; ++i)
	{
		if (word.at(i) != word.at(word.size() - 1 - i))
			return false;
	}
	return true;
}