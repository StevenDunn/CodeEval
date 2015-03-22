// Sum Of Integers solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::max;
using std::remove;
using std::replace;
using std::string;
using std::vector;

vector<int> parseLine(string);
int getSum(vector<int>);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<int> numbers = parseLine(line);
			printf("%d\n", getSum(numbers));
		}
		inputFile.close();
	}
	
	return 0;
}

vector<int> parseLine(string line)
{
	line.erase(remove(line.begin(), line.end(), ' '), line.end());
	replace(line.begin(), line.end(), ',', ' ');
	
	vector<int> result;
	string s;
	istringstream iss(line);
	while (iss >> s)
		result.push_back(atoi(s.c_str()));
	
	return result;
}

int getSum(vector<int> numbers)
{
	// Kadane's algorithm
	int maxEndingHere = 0;
	int maxSoFar = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		maxEndingHere = max(0, maxEndingHere + numbers[i]);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	
	return maxSoFar;
}