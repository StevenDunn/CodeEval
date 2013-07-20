// Reverse Words program written in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline (inputFile, line))
		{
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			cout << line << endl;
		}
	}
	else perror("UNABLE TO OPEN INPUT FILE");
}