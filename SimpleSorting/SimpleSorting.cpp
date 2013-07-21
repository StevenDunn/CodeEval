// Simple Sorting solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			istringstream iss(line);
			vector<string> tokens;
			copy(istream_iterator<string>(iss),
			         istream_iterator<string>(),
			         back_inserter<vector<string> >(tokens));

			vector<double> nums;
			double val = 0;
			for (int i = 0; i < tokens.size(); i++)
			{
				val = atof(tokens[i].c_str());
				nums.push_back(val);
			}
			sort(nums.begin(), nums.end());
			
			cout.setf(ios::fixed, ios::floatfield);
			cout.precision(3);
			for (int i = 0; i < nums.size(); i++)
			{
				cout << nums[i] << " ";
			}
			cout << endl;
		}
	}
}