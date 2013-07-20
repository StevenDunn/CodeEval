// Multiplication Tables program written in C++ for CodeEval.com by Steven A. Dunn

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main (int argc, int argv[])
{
	for(int i = 1; i <= 12; i++) 
	{
		for(int j = 1; j <= 12; j++) 
		{
			if(j == 1)
				printf("%2d", i*j);
			else
				printf("%4d", i*j);
		}
		cout << endl;
	}	
}