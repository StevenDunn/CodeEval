// find the highest score soln in c++ for code eval by steven a dunn

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

vector<int> tokenize(string);

int main (int argc, char* const argv[])
{
	ifstream input_file(argv[1]);
	string line;
	
	if(input_file)
	{
		while (getline(input_file, line))
		{
			vector<int> tokenize(line);
		}
		input_file.close();
	}
	return 0;
}

vector<int> tokenize(string input)
{
	vector<int> dummy;
	return dummy;
}