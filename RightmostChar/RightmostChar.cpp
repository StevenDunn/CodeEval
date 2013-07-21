// Rightmost Care solution written in C++ for CodeEval.com by Steven A. Dunn

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
			char lastChar = line[line.size()-1];
			for (int strIdx = line.size() - 3; strIdx >= 0; strIdx--)
			{
				if (line[strIdx] == lastChar) 
				{ 
					cout << strIdx << endl; 
					break; 
				}
				if (strIdx == 0) { cout << "-1" << endl; }
			}
		}
	}
}