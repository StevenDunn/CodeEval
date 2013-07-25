// Pangrams solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::transform;
using std::vector;

bool isLetter(char);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile,line))
		{
			if (line == "")
				continue;
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			vector<int> letters(26, 0);
			vector<char> missingLetters;
			
			for(int i = 0; i < line.length(); ++i) 
				if (isLetter(line.at(i)))
					letters[line.at(i) - 'a'] = 1;
		
			for(int i = 0; i < 26; ++i) 
				if(letters[i] == 0)
					missingLetters.push_back(i + 'a');
					
			if(missingLetters.size() == 0)
				cout << "NULL" << endl;
			else
			{
				for (int i = 0; i < missingLetters.size(); ++i)
					cout << missingLetters[i];
				cout << endl;
			}
		}
		inputFile.close();
	}
	return 0;
}

bool isLetter(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	return false;
}