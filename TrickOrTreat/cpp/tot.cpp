// trick or treat soln in cpp for code eval by steven a dunn

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<string> tokenize(string, char);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			vector<string> entries = tokenize(line, ',');
			vector<int> vals;
			for (int i = 0; i < entries.size(); ++i)
			{
				vector<string> tokens = tokenize(entries[i], ':');
				vals.push_back(atoi(tokens[1].c_str()));
			}
			printf("%d\n", (((3 * vals[0]) + (4 * vals[1]) + (5 * vals[2])) * vals[3])/(vals[0] + vals[1] + vals[2]) );
		}
		input_file.close();
	}
	return 0;
}

vector<string> tokenize(string line, char delim)
{
	vector<string> tokens;
	istringstream iss(line);
	string token;

	while(getline(iss, token, delim))
		tokens.push_back(token);

	return tokens;
}