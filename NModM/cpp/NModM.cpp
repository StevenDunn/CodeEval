// N Mod M solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			size_t commaPos = line.find(",");
			int n = atoi(line.substr(0, commaPos).c_str());
			int m = atoi(line.substr(commaPos + 1).c_str());

			int x = n / m;
			int y = x * m;
			int mod = n - y;
			
			cout << mod << endl;
		}
	}
}