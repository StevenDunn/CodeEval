// Trailing String solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			if (line == "")
				continue;
			int commaPos = line.find(",");
			string text = line.substr(0, commaPos);
			string trail = line.substr(commaPos + 1);

			if (trail.size() > text.size())
				cout << 0 << endl;
			else if (text.substr(text.size() - trail.size()) == trail)
				cout << 1 << endl;
			else
				cout << 0 << endl;	
		}
		inputFile.close();
	}
	
	return 0;
}