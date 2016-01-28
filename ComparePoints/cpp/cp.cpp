// compare points soln in c++ for code eval by steven a dunn

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

vector<int> tokenize(string);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			int o, p, q, r;
			string result;
			vector<int> points = tokenize(line);

			o = points[0];
			p = points[1];
			q = points[2];
			r = points[3];

			if (o == q)
			{
				if (p == r)
					result = "here";
				if (p < r)
					result = "N";
				if (p > r)
					result = "S";
			}
			if (o < q)
			{
				if (p == r)
					result = "E";
				if (p < r)
					result = "NE";
				if (p > r)
					result = "SE";
			}
			if (o > q)
			{
				if (p == r)
					result = "W";
				if (p < r)
					result = "NW";
				if (p > r)
					result = "SW";
			}
			puts(result.c_str());
		}
		input_file.close();
	}

	return 0;
}

vector<int> tokenize(string line)
{
    vector<int> tokens;
    istringstream iss(line);
    string token;
    while (getline(iss, token, ' '))
        tokens.push_back(atoi(token.c_str()));
    return tokens;
}
