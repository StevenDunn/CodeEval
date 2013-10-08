// Closest Pair solution in C++ for CodeEval.com by Steven A. Dunn

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

struct Tuple 
{
  int x;
  int y;
  Tuple(int x, int y) : x(x), y(y) {} 
};

double MAX_DISTANCE = 10000;

vector<Tuple> tuples;

double findClosestPair(vector<Tuple>);
double findDistance(Tuple, Tuple);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while(getline(inputFile, line))
    {
      int N = atoi(line.c_str());
      if (N == 0)
        break;

      for (int i = 0; i < N; ++i)
      {
        getline(inputFile, line);
        istringstream iss(line);
        string x, y;
        iss >> x;
        iss >> y;

        Tuple t(atoi(x.c_str()), atoi(y.c_str()));

        tuples.push_back(t);
      }

      double result = findClosestPair(tuples);
      if (result < MAX_DISTANCE)
        printf("%.4f\n", findClosestPair(tuples));
      else
        printf("INFINITY\n");

      tuples.clear();
    }
    inputFile.close();
  }

  return 0;
}

double findClosestPair(vector<Tuple> tuples)
{
  double minDistance = MAX_DISTANCE;
  for(int i = 0; i < tuples.size(); ++i)
  {
    for(int j = i + 1; j < tuples.size(); ++j)
    {
      double dist = findDistance(tuples[i], tuples[j]);
      if (dist < minDistance)
        minDistance = dist;
    }
  }

  return minDistance;
}

double findDistance(Tuple t1, Tuple t2)
{
  return sqrt( 
      pow( (t2.x - t1.x), 2) + 
      pow( (t2.y - t1.y), 2)); 
}
