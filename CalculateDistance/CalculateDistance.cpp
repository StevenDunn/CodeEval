// Calculate Distance solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Point
{
public:
	Point(int a, int b) { x = a; y = b; }
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;
	int y;
};


vector<string> parseLine(string);
Point createPoint(string, string);
int calculateDistance(Point, Point);

int main(int argc, char* argv[])
{
	ifstream inputFile(argv[1]);
	string line;
	
	if (inputFile)
	{
		while (getline(inputFile, line))
		{
			vector<string> tokens = parseLine(line);
			Point p1 = createPoint(tokens[0], tokens[1]);
			Point p2 = createPoint(tokens[2], tokens[3]);

			int distance = calculateDistance(p1, p2);
			cout << distance << endl;
		}
		inputFile.close();
	}
}

vector<string> parseLine(string line)
{
	char chars[] = "(),";
	stringstream ss (line);	
	string s;
	vector<string> tokens;
	while (ss >> s)
	{
		for (int i = 0; i < strlen(chars); ++i)
		s.erase(remove(s.begin(), s.end(), chars[i]), s.end());
		tokens.push_back(s);
	}
	return tokens;
}

Point createPoint(string s1, string s2)
{
	Point p(atoi(s1.c_str()), atoi(s2.c_str()));
	return p;
}

int calculateDistance(Point p1, Point p2)
{
	int x1 = p1.getX();
	int y1 = p1.getY();
	
	int x2 = p2.getX();
	int y2 = p2.getY();
	
	int distance = (int)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	
	return distance;
}