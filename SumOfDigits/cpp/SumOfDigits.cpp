// Sum of Digits program written in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);

  	string line;

  	if(inputFile)
  	{	
		while(getline(inputFile, line))
    	{
			int n = atoi(line.c_str());
			int part = 0; 
			int sum = 0;
			
			while(n > 0) 
			{
				part = (n % 10);
				sum += part;
				n = (n/10);
			}
			std::cout << sum << std::endl;
		}	
  	}
}