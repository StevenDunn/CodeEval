// testing soln in cpp for code eval by steven a dunn

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <functional>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<string> tokenize(string line);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			vector<string> tokens = tokenize(line);

			// trim the ends b/c of the spaces next to the vertical bar
			tokens[0] = tokens[0].substr(0, tokens[0].size()-1);
			tokens[1] = tokens[1].substr(1);
			int bug_count = 0;

			for (int i = 0; i < tokens[0].size(); ++i)
				if (tokens[0][i] != tokens[1][i])
					++bug_count;

			string result;
			if (bug_count == 0)
				result = "Done";
			else if (bug_count <= 2)
				result = "Low";
			else if (bug_count <= 4)
				result = "Medium";
			else if (bug_count <= 6)
				result = "High";
			else
				result = "Critical";

			puts(result.c_str());

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
    while (getline(iss, token, '|'))
        tokens.push_back(token);
    return tokens;
}

