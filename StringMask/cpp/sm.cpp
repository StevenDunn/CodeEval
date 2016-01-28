// string mask soln in cpp for code eval by steven a dunn

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<string> tokenize(string);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			vector<string> input = tokenize(line);
			string text = input[0];
			string bin = input[1];

			for (int i = 0; i < text.size(); ++i)
			{
				if (bin[i] == '1')
					printf("%c", toupper((unsigned char)(text[i])));
				else if (bin[i] == '0')
					printf("%c", tolower((unsigned char)(text[i])));
			}
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
        tokens.push_back(token);
    return tokens;
}
