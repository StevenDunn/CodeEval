// Unique Elements program written in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main (int argc, char* argv[])
{
	ifstream inputFile (argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline (inputFile, line))
		{
			stringstream ss (line);	
			int i;
			vector<int> tokens;
			while (ss >> i)
			{
				tokens.push_back(i);
				if (ss.peek() == ',')
					ss.ignore();
			}
			sort (tokens.begin(), tokens.end());	
			std::set<int> tokenSet (tokens.begin(), tokens.end());
			
			for (set<int>::iterator it = tokenSet.begin(); it != tokenSet.end(); ++it)
			{
				set<int>::iterator peek = it;
				peek++;
				if (peek != tokenSet.end())
			    	cout << *it << ",";
				else
					cout << *it << endl;
			}
		}
	}
}