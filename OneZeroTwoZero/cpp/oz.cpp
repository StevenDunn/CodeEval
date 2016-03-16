// one zero two zeros soln for code eval by steven a dunn

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::bitset;
using std::count;
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
			vector<int> input = tokenize(line);
			int num_zeros = input[0];
			int max_num = input[1];
			int num_count = 0;

			for (int i = 1; i < max_num + 1; ++i)
			{
			    string binary = bitset<10>(i).to_string();
			    int one_idx = binary.find('1');
			    if (one_idx != string::npos)
			    	binary = binary.substr(binary.find('1'));

			    int zeros = count(binary.begin(), binary.end(), '0');
			    if (zeros == num_zeros)
			      ++num_count;
			}
  			printf("%d\n", num_count);
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
	while(getline(iss, token, ' '))
		tokens.push_back(atoi(token.c_str()));
	return tokens;
}