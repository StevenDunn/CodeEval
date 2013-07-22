// Even Numbers solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			int n = atoi(line.c_str());
			if (n % 2 == 0) { cout << "1" << endl; }
			else { cout << "0" << endl; } 
		}
	}
}