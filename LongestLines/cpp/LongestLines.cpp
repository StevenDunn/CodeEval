// Longest Lines solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		getline(inputFile, line);
		int N = atoi(line.c_str());
		vector<string> longestLines(N, "");
		
		while (getline(inputFile, line))
		{
			if (line == "") 
				continue;
			for (int i = 0; i < N; ++i)
			{
				if (longestLines.at(i).size() > line.size()) 
					continue;
				else 
				{
					vector<string>::iterator it = longestLines.begin();
					longestLines.insert(it + i, line);
					break;
				}	
			}
			if (longestLines.size() > N)
				longestLines.resize(N);
		}
		for (int i = 0; i < longestLines.size(); ++i)
			cout << longestLines[i] << endl;
		
		inputFile.close();
	}
	
	return 0;
}