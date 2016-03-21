// not so clever soln in cpp for code eval by steven a dunn

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
vector<int> tokenize(string);
void stupid_sort(vector<int> &);
void swap(vector<int>&, int, int);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;

	if (input_file)
	{
		while(getline(input_file, line))
		{
			vector<string> tokens = tokenize(line, '|');
			vector<int> nums = tokenize(tokens[0]);
			int iterations = atoi(tokens[1].c_str());

			for (int i = 0; i < iterations; ++i)
				stupid_sort(nums);

			for (int i = 0; i < nums.size(); ++i)
				printf("%d ", nums[i]);
			puts("");
		}	
		input_file.close();
	}
	return 0;
}

vector<string> tokenize(string line, char delim)
{
	istringstream iss(line);
	string token;
	vector<string> tokens;
	while (getline(iss, token, delim))
		tokens.push_back(token);
	return tokens;
}

vector<int> tokenize(string line)
{
	istringstream iss(line);
	string token;
	vector<int> tokens;
	while (getline(iss, token, ' '))
		tokens.push_back(atoi(token.c_str()));
	return tokens;
}

void stupid_sort(vector<int> & nums)
{
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		if (nums[i] > nums[i+1])
		{
			swap(nums, i, i+1);
			break;
		} 
	}
}

void swap(vector<int> & nums, int i, int j)
{
	int tmp = nums[i];
	nums[i] = nums[j];
	nums[j] = tmp;
}
