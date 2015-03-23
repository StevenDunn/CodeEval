// Overlapping Rectangles solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::replace;
using std::string;
using std::vector;

vector<int> parseLine(string);
string detectOverlap(vector<int>);
bool isOverlap(int, int, int, int);
void swap(int&, int&);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			replace(line.begin(), line.end(), ',', ' ');
			vector<int> tokens = parseLine(line);
			cout << detectOverlap(tokens) << endl;
		}
		inputFile.close();
	}
	
	return 0;
}

vector<int> parseLine(string line)
{
	istringstream iss(line);
	string s;
	vector<int> tokens;
	while (iss >> s)
	{
		tokens.push_back(atoi(s.c_str()));
	}
	return tokens;	
}

string detectOverlap(vector<int> coords)
{
	int Ax1 = coords[0];
	int Ay1 = coords[1];
	int Ax2 = coords[2];
	int Ay2 = coords[3];
	
	int Bx1 = coords[4];
	int By1 = coords[5];
	int Bx2 = coords[6];
	int By2 = coords[7];
	
	if(isOverlap(Ax1, Ax2, Bx1, Bx2) && isOverlap(Ay1, Ay2, By1, By2))
		return "True";
	return "False";	
}

bool isOverlap(int a1, int a2, int b1, int b2)
{
	if (a1 > a2)
		swap(a1, a2);
		
	if (b1 > b2)
		swap(b1, b2);

	bool overlap = false;
	for (int i = a1; i <= a2; ++i)
		if (i >= b1 && i <= b2)
			overlap = true;
	return overlap;
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}