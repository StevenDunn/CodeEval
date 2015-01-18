// Hex to Decimal solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			stringstream ss;
			ss << line;
			
			int x;
			ss >> hex >> x;
			
			cout << x << endl;
		}
	}
}