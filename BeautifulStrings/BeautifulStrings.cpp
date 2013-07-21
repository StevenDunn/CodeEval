// Beautiful Strings solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
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
			const int ASCII_CONVERSION_VALUE = 97;
			vector<int> counts(26, 0);
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			for (int strIdx = 0; strIdx < line.length(); strIdx++)
			{
				if (line[strIdx] - ASCII_CONVERSION_VALUE >= 0 && 
					line[strIdx] - ASCII_CONVERSION_VALUE <= 25)
				{  
					counts[line[strIdx] - ASCII_CONVERSION_VALUE]++;
				}
			}
			sort(counts.begin(), counts.end());
			
			int beauty = 0;
			int weight = 26;
			for (int countsIdx = counts.size(); countsIdx >= 0; countsIdx--)
			{
				beauty += (weight * counts[countsIdx-1]);
				weight--;
			}
			cout << beauty << endl;
		}
	}
}