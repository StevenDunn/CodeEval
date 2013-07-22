// Capitalize Words solution in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<string> words;
			istringstream iss(line);
			copy(istream_iterator<string>(iss), 
		      istream_iterator<string>(), 
		      back_inserter<vector<string> >(words));
		
			for (int i = 0; i < words.size(); i++)
	    	{
	      		if ((char)words[i].at(0) >= 97)
				{
					cout << (char)(words[i].at(0) - 32);
					cout << words[i].substr(1) << " ";
				}
				else
				{
					cout << words[i] << " ";
				}
	    	}
			cout << endl;
		}
	}
}