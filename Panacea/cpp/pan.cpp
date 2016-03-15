// panacea soln in cpp for code eval by steven a dunn

#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

vector<string> tokenize(string s, char delim);
vector<long> tokenize(string s, int base);
int calc_sum(vector<long> nums);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while (getline(input_file, line))
		{
			vector<string> tokens = tokenize(line, '|');
			vector<long> virs = tokenize(tokens[0], 16);
			vector<long> ants = tokenize(tokens[1], 2);

			int vir_sum = calc_sum(virs);
			int ant_sum = calc_sum(ants);

			if (vir_sum <= ant_sum)
				puts("True");
			else
				puts("False");
		}
	}
	return 0;
}

vector<string> tokenize(string s, char delim)
{
	vector<string> tokens;
	istringstream iss(s);
	string token;

	while (getline(iss, token, delim))
		tokens.push_back(token);
	return tokens;
}

vector<long> tokenize(string s, int base)
{
	vector<long> tokens;
	istringstream iss(s);
	string token;

	while (getline(iss, token, ' '))
		tokens.push_back(strtol(token.c_str(), NULL, base));
	return tokens;
}

int calc_sum(vector<long> nums)
{
	long total = 0;
	for (int i = 0; i < nums.size(); ++i)
		total += nums[i];
	return total;
}