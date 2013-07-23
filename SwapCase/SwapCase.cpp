// Swap Case solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			for(int i = 0; i < line.length(); i++)
			{
				char c = line.at(i);
				if(c >= 65 && c <= 90)
					c = c + 32;
				else if (c >= 97 && c <= 122)
					c = c - 32;
				cout << c;
			}
			cout << endl;
		}
		inputFile.close();
	}
}