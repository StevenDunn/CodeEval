// Remove Characters solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::remove;
using std::string;
using std::vector;

string strip(string, string);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			string text = line.substr(0, line.find(","));
			string letters = line.substr(line.find(",") + 2);
			string result = strip(text, letters);
			
			cout << result << endl;
		}
		inputFile.close();
	}	
	return 0;
}

string strip(string line, string letters)
{
	for (int i = 0; i < letters.size(); ++i)
		line.erase(remove(line.begin(), line.end(), letters.at(i)), line.end());
	return line;
}