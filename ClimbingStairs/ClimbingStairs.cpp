// Climbing Stairs solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

long getNumClimbs(string);
long fib(int);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if(inputFile)
	{
		while(getline(inputFile, line))
			cout << getNumClimbs(line) << endl;
		inputFile.close();
	}
}

long getNumClimbs(string steps)
{
	int stepsNum = atoi(steps.c_str());
	long numClimbs = fib(stepsNum + 1);
	return numClimbs;
}

long fib(int n)
{
	long buf1 = 1;
	long buf2 = 1;
	long temp = 0;
	
	if (n == 1 || n == 2) { return 1; }
	else 
	{
		for (int fibIdx = 3; fibIdx <= n; fibIdx++)
		{
			temp = buf1;
			buf1 = buf2;
			buf2 = buf1 + temp;
		}
	}
	return buf2;
}