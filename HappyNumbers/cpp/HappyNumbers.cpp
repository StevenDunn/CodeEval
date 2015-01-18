// Happy Numbers solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isHappy (int);

static vector<int> visited;

int main(int argc, char* argv[])
{
	ifstream inputFile (argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			int n = atoi(line.c_str());
			if (isHappy(n)) { cout << "1" << endl; }
			else { cout << "0" << endl; }
			visited.clear();
		}
	}
}

bool isHappy(int n)
{
	int sum = 0;
	int part = 0;
	
	while (n > 0) 
	{
		part = (n % 10);
		sum += (part * part);
		n = (n/10);
	}
	
	if (sum == 1) { return true; }
	
	for (int i = 0; i < visited.size(); i++)
	{
		if (i == sum) { return false; }
	}	
	visited.push_back(sum);
	
	if (isHappy(sum)) { return true; }
	
	return false;
}