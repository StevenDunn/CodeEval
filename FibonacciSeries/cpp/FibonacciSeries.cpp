// Fibonacci Series program written in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

long fib(int);

int main (int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{	
		while (getline(inputFile, line))
		{
			int n = atoi(line.c_str());
			cout << fib(n) << endl;
		}
	}
}

long fib (int n)
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