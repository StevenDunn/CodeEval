// Number of Ones solution in C++ for CodeEval.com by Steven A. Dunn

#include <bitset>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using std::bitset;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			int n = atoi(line.c_str());
			string binaryString = bitset<64>(n).to_string();
			
			int count = 0;
			for (int i = 0; i < binaryString.size(); ++i)
				if (binaryString.at(i) == '1')
					++count;
			cout << count << endl;	
		}
		inputFile.close();
	}
	return 0;
}