// time to eat soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

using std::greater;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

vector<string> tokenize(string);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while (getline(input_file, line))
		{
			vector<string> timestamps = tokenize(line);
			sort(timestamps.begin(), timestamps.end(), greater<string>());
			for (int i = 0; i < timestamps.size(); ++i)
				printf("%s ", timestamps[i].c_str());
			puts("");
		}
		input_file.close();
	}

	return 0;
}

vector<string> tokenize(string line)
{
	vector<string> tokens;
	istringstream iss(line);
	string token;
	while (getline(iss, token, ' '))
	{
		if (token[token.size()] == '\n')
			token[token.size()] = '\0';
		if (token[token.size()-1] == '\r')
			token[token.size()-1] = '\0';

		tokens.push_back(token);
	}
	return tokens;
}