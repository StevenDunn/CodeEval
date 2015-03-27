// Point In Circle solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::replace;
using std::string;
using std::vector;

vector<float> parseLine(string);
string inCircle(vector<float>);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      vector<float> coords = parseLine(line);
      cout << inCircle(coords) << endl;
    }
    inputFile.close();
  }
  return 0;
}

vector<float> parseLine(string line)
{
  vector<float> result;

  line = line.substr(line.find("(")); 
  string centerStr = line.substr(0, line.find(")"));
  replace(centerStr.begin(), centerStr.end(), '(', ' ');
  result.push_back(atof(centerStr.substr(0, centerStr.find(",")).c_str()));
  result.push_back(atof(centerStr.substr(centerStr.find(",") + 1).c_str()));

  line = line.substr(line.find(":") + 2);
  result.push_back(atof(line.substr(0, line.find(";")).c_str()));

  string pointStr = line.substr(line.find(":") + 1);
  replace(pointStr.begin(), pointStr.end(), '(', ' ');
  replace(pointStr.begin(), pointStr.end(), ')', ' ');
  result.push_back(atof(pointStr.substr(0, pointStr.find(",")).c_str()));
  result.push_back(atof(pointStr.substr(pointStr.find(",") + 1).c_str()));

  return result;
}

string inCircle(vector<float> coords)
{
  float cx = coords[0];
  float cy = coords[1];
  float r = coords[2];
  float px = coords[3];
  float py = coords[4];

  if (sqrt( (cx - px) * (cx - px) + (cy - py) * (cy - py) ) > r)
    return "false";
  return "true";
}
