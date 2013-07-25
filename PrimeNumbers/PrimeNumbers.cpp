// Prime Numbers solution in C++ for CodeEval.com by Steven A. Dunn

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;

void writePrimes(unsigned long);
bool isPrime(unsigned long n);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			unsigned long n = atol(line.c_str());
			writePrimes(n);
		}
		inputFile.close();
	}
	
	return 0;
}

void writePrimes(unsigned long n)
{
	if (n >= 2)
		printf("2");
	for (unsigned long i = 3; i < n; ++i)
		if (i % 2 != 0 && isPrime(i))
			printf(",%lu", i);
	printf("\n");
}

bool isPrime(unsigned long n)
{
	unsigned long root = sqrt(n);
	for (unsigned long i = 3; i <= root; ++i) 
		if (n % i == 0)
			return false;
	return true;
}