// Pascal's Triangle solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::string;
using std::vector;

string createPascalsTriangle(int);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			int depth = atoi(line.c_str());
			cout << createPascalsTriangle(depth) << endl;
		}
		inputFile.close();
	}
	return 0;
}

string createPascalsTriangle(int depth)
{
	ostringstream triangle;
	triangle << "1 ";
	
	vector<int> previousLine(1, 1);
	vector<int> thisLine;
	for (int i = 2; i <= depth; ++i)
	{
		thisLine.clear();
		triangle << "1 ";
		thisLine.push_back(1);
		for (int j = 0; j < previousLine.size() - 1; ++j)
		{
			int nextVal = previousLine.at(j) + previousLine.at(j+1);
			thisLine.push_back(nextVal);
			triangle << nextVal << " ";
		}
		triangle << "1 ";
		thisLine.push_back(1);
		previousLine = thisLine;
	}
	
	return triangle.str();
}