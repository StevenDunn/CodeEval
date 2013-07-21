// Double Squares solution in C++ for CodeEval.com by Steven A. Dunn

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getNumDoubleSquares(long number);

// length is the sqrt of the max input divided by 2
static int cachedVals[32767];

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		getline(inputFile, line);
		while(getline(inputFile, line))
		{
			int result = getNumDoubleSquares(atol(line.c_str()));
			cout << result << endl;
		}
	}
}

int getNumDoubleSquares(long number)
{
	int count = 0;
	int upperLimit = sqrt(number/2);
	for (int i = 0; i <= upperLimit; i++)
	{
		if (cachedVals[i] == 0) { cachedVals[i] = i*i; }
		
		double j = sqrt((double)number - cachedVals[i]);
		if (j - (int)j == 0.0) { count++; }
	}
	return count; 
}