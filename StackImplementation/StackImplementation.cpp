// Stack Implementation solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
#include <sstream>
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
			while (!numStack.empty())
			{
				cout << numStack.top() << " ";
				numStack.pop();
				
				if (!numStack.empty())
					numStack.pop();
			}
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
		result.push_back(atoi(s.c_str()));
		
	return result;
}