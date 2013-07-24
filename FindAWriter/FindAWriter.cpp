// Find A Writer solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> parseLine(string);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			if (line != "")
			{
				string encryptedName = line.substr(0, line.find('|'));
				string key = line.substr(line.find('|') + 1);
				vector<int> keys = parseLine(key);
				
				for (int i = 0; i < keys.size(); ++i)
					cout << encryptedName.at(keys[i] - 1);
				cout << endl;  
			}
		}
		inputFile.close();
	}
}

vector<int> parseLine(string line)
{
	istringstream iss(line);
	string s;
	vector<int> tokens;	
	while (iss >> s)
	{
		tokens.push_back(atoi(s.c_str()));
	}
	return tokens;
}