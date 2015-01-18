// Sum Of Integers From File program written in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[])
{
	ifstream inputFile (argv[1]);
	string line;
	int sum = 0;
	
	if (inputFile)
		while (getline(inputFile, line)) { sum += atoi(line.c_str()); }
	cout << sum << endl;		
}