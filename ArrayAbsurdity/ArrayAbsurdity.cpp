// Array Absurdity solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
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
			size_t semicolonPos = line.find(";");
			line = line.substr(semicolonPos + 1);
			stringstream ss(line);
			int i;
			vector<int> tokens;
			while (ss >> i)
			{
				tokens.push_back(i);

				if (ss.peek() == ',')
					ss.ignore();
			}

			sort(tokens.begin(), tokens.end());
					
			for(int i = 0; i < tokens.size(); i++)
			{
				if(tokens[i] != i) 
				{ 
					cout << tokens[i] << endl; 
					break;
				}
			}
		}
	}
}