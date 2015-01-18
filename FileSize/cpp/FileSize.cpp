// File Size program written in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>

using namespace std;

int main (int argc, char* argv[])
{
	ifstream inputFile (argv[1], ifstream::binary);
	if (inputFile) 
	{
		inputFile.seekg (0, inputFile.end);
	    int length = inputFile.tellg();
		cout << length << endl;
	}
}