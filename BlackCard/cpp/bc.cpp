// black card soln in cpp for code eval by steven a dunn

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<string> tokenize(string, char = ' ');

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			vector<string> tokens = tokenize(line, '|');
			vector<string> people = tokenize(tokens[0]);
			int n = atoi(tokens[1].c_str()) - 1;

			while (people.size() > 1)
			{
				int idx = n % people.size();
				people.erase(people.begin() + idx);
			}
			printf("%s\n", people[0].c_str());
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
	while (getline(iss, token, delim))
		tokens.push_back(token);
	return tokens;
}