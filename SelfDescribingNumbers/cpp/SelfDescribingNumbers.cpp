// Self Describing Numbers solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool isSelfDescribing(int);

vector<int> counts(10, 0);

int main(int argc, char* argv[])
{
	ifstream inputFile (argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			int n = atoi(line.c_str());
			if (isSelfDescribing(n)) { cout << "1" << endl; }
			else { cout << "0" << endl; }
			counts.clear();
			counts.resize(10);
		}
	}
}

bool isSelfDescribing(int number)
{
	const int ASCII_TO_INT_CONVERSION = 48;
	int digit = 0;
	int n = number;
	while (n > 0)
	{
		digit = (n % 10);
		counts[digit]++;
		n = (n/10);
	}
	ostringstream numSS;
	numSS << number;
	string numStr = numSS.str();
	
	for (int i = 0; i < numStr.size(); i++)
	{
		if (numStr.at(i) - ASCII_TO_INT_CONVERSION != counts[i]) { return false; }
	}
	return true;
}