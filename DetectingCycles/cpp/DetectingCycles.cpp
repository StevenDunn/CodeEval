// Detecting Cycles solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::stack;
using std::string;
using std::vector;

vector<int> parseLine(string);
bool contains(vector<int>, int);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<int> numbers = parseLine(line);
			
			stack<int> numStack;
			for (int i = 0; i < numbers.size(); ++i)
				numStack.push(numbers[i]);
			
			int num = 0;
			vector<int> unique;
			vector<int> seq;
			while (!numStack.empty())
			{
				num = numStack.top();
				numStack.pop();
				if (!contains(unique, num))
					unique.push_back(num);
				else if (!contains(seq, num))
					seq.push_back(num);
			}
			
			for (int i = seq.size() - 1; i >= 0; --i)
				cout << seq[i] << " ";
			cout << endl;
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
	{
		result.push_back(atoi(s.c_str()));
	}
	
	return result;
}

bool contains(vector<int> vec, int val)
{
	for (int i = 0; i < vec.size(); ++i)
		if (vec[i] == val)
			return true;
	return false;
}