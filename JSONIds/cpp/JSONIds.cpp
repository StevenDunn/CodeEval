// JSON IDs solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string, string);
int getIdValue(string);

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
				vector<string> idTokens = split(line, "id");
				vector<string> labelTokens;
				int sum = 0;
				for(int i = 0; i < idTokens.size(); ++i)
				{
					labelTokens = split(idTokens[i], "label");
					if (labelTokens.size() > 1 && 
						labelTokens[0].at(0) == 'd' && 
						labelTokens[1].at(0) == 'a')
					{
						int idValue = getIdValue(labelTokens[0]);
						sum += idValue;
					}
				}
				cout << sum << endl;
			}
		}
		inputFile.close();
	}
}

vector<string> split(string line, string delimiter)
{
	vector<string> tokens;
	size_t prev, pos;
	prev = pos = 0;
	while ((pos = line.find(delimiter, prev)) !=  string::npos)
	{
		if (pos > prev)
			tokens.push_back(line.substr(prev, pos - prev));
		prev = pos + 1;
	}
	if (prev < line.size())
	{
		tokens.push_back(line.substr(prev, string::npos));
	}
	
	return tokens;
}

int getIdValue(string word)
{
	char chars[] = "{}abcdefghijklmnopqrstuvwxyz:\", ";
	for(int i = 0; i < strlen(chars); ++i)
		word.erase(remove(word.begin(), word.end(), chars[i]), word.end());
	int result = atoi(word.c_str());
	return result;
}