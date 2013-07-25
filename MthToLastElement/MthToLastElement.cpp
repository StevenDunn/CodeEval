// Mth To Last Element solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<string> parseLine(string);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<string> tokens = parseLine(line);
			int M = atoi(tokens[tokens.size() - 1].c_str());
			int element = tokens.size() -1 - M;
				if (element >= 0)
					cout << tokens[element] << endl;
				else
					continue;
		}
		inputFile.close();
	}
	return 0;
}

vector<string> parseLine(string line)
{
	vector<string> result;
	string s;
	istringstream iss(line);
	while (iss >> s)
		result.push_back(s);
		
	return result;
}