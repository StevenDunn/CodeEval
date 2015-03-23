// Number Pairs solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::replace;
using std::string;
using std::vector;

vector<int> parseLine(string);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			if (line == "")
				continue;
				
			int semicolonPos = line.find(";");
			string list = line.substr(0, semicolonPos);
			replace(list.begin(), list.end(), ',', ' ');
			
			vector<int> nums = parseLine(list);
			
			int sum = atoi(line.substr(semicolonPos + 1).c_str());
			
			ostringstream oss;
			for (int i = 0; i < nums.size() - 1; ++i)
				for (int j = i + 1; j < nums.size(); ++j)
					if (nums[i] + nums[j] == sum)
						oss << nums[i] << "," << nums[j] << ";";
			string result = oss.str();
			if (result == "")
				cout << "NULL" << endl;
			else
				cout << result.substr(0, result.size() - 1) << endl;
		}
		inputFile.close();
	}
	return 0;
}

vector<int> parseLine(string line)
{
	vector<int> result;
	string s;
	istringstream iss(line);
	while (iss >> s)
		result.push_back(atoi(s.c_str()));
		
	return result;	
}