// Find A Square solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cmath>
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
using std::sort;
using std::string;
using std::vector;

class Point
{
  public:
    Point()
    {
      this->x = 0;
      this->y = 0;
    }
    Point(int x, int y) 
    { 
      this->x = x; 
      this->y = y; 
    }
    int getX() { return x; }
    int getY() { return y; }
  private:
    int x;
    int y;
};

vector<Point> parseLine(string);
string findASquare(vector<Point>);
bool isSquare(vector<Point>);
int distance(Point, Point);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      vector<Point> coords = parseLine(line);
      cout << findASquare(coords) << endl;
    }
    inputFile.close();
  }
  return 0;
}

vector<Point> parseLine(string line)
{
  replace(line.begin(), line.end(), '(', ' ');
  replace(line.begin(), line.end(), ')', ' ');
  replace(line.begin(), line.end(), ',', ' ');

  vector<string> vals;
  istringstream iss(line);
  string s;
  while( iss >> s)
    vals.push_back(s);

  vector<Point> result;
  for (int i = 0; i < vals.size() - 1; i = i + 2)
  {
    Point p(atoi(vals[i].c_str()), atoi(vals[i+1].c_str()));
    result.push_back(p);
  }  

  return result;
}

string findASquare(vector<Point> points)
{
  if (isSquare(points))
    return "true";
  return "false";
}

bool isSquare(vector<Point> points)
{
  vector<int> distances;
  for (int i = 0; i < points.size(); ++i)
    for (int j = i + 1; j < points.size(); ++j)
      distances.push_back(distance(points[i], points[j]));  
  sort(distances.begin(), distances.end());

  if (distances[0] == distances[1] &&
      distances[1] == distances[2] &&    
      distances[2] == distances[3] &&
      distances[4] == distances[5])
    return true; 

  return false;
}

int distance(Point p1, Point p2)
{
  int x2 = (p2.getX() - p1.getX()) * (p2.getX() - p1.getX());
  int y2 = (p2.getY() - p1.getY()) * (p2.getY() - p1.getY());
  int result = (int)sqrt(x2 + y2);
  return result;
}
