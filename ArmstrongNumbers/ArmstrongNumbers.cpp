// Armstrong numbers solution written in C++ for CodeEval.com by Steven A. Dunn

#include <cmath>
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
			int number = atoi(line.c_str());
			
			int numDigits = 0;
			int part = 0; 

			int n = number;
			while (n > 0) 
			{
				part = (n % 10);
				numDigits++;
				n = (n/10);
			}
			
			n = number;
			double sum = 0;
			while (n > 0)
			{
				part = (n % 10);
				sum += pow((double)part, (double)numDigits);
				n = (n/10);
			}
			if ((int)sum == number) { cout << "True" << endl; }
			else { cout << "False" << endl; }
			
		}
	}
}