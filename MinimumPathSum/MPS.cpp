// Minimum Path Sum solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream_iterator;
using std::istringstream;
using std::pair;
using std::replace;
using std::string;
using std::vector;

typedef pair<int, pair<int, int> > Node;

vector<string> tokenize(string);
int findMinSum(vector< vector<int> >);
Node getSmallest(vector<Node>, int&);
bool isEnd(Node, int);
Node* getAdjacentX(Node, vector<vector<int> >);
Node* getAdjacentY(Node, vector<vector<int> >);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while(getline(inputFile, line))
    {
      int N = atoi(line.c_str());
      vector< vector<int> > matrix(N, vector<int>(N));

      for (int i = 0; i < N; ++i) 
      {
        getline(inputFile, line);

        replace(line.begin(), line.end(), ',', ' ');
        vector<string> tokens = tokenize(line);

        for (int j = 0; j < N; ++j)
          matrix[i][j] = atoi(tokens[j].c_str());
      }

      int minSum = findMinSum(matrix);
      cout << minSum << endl; 
    }

    inputFile.close();
  }
  return 0;
}

vector<string> tokenize(string line)
{
  vector<string> tokens;
  istringstream iss(line);

  copy(
      istream_iterator<string>(iss), 
      istream_iterator<string>(), 
      back_inserter<vector<string> >(tokens));

  return tokens;
}

int findMinSum(vector< vector<int> > matrix)
{
  int minSum = matrix[0][0];
  vector<Node> sums;

  Node init(minSum, pair<int, int>(0, 0)); 
  sums.push_back(init);

  while (!sums.empty())
  {
    int smallestIdx = 0;
    Node smallest = getSmallest(sums, smallestIdx);

    if (isEnd(smallest, matrix.size()))
      return smallest.first;

    Node *adjx = getAdjacentX(smallest, matrix);
    Node *adjy = getAdjacentY(smallest, matrix);

    if (adjx)
      sums.push_back(*adjx);
    if (adjy)
      sums.push_back(*adjy);

    sums.erase(sums.begin() + smallestIdx);
  }
}

Node getSmallest(vector<Node> sums, int& smallestIdx)
{
  int smallestSum = sums[0].first;
  Node smallest = sums[0];

  for (int i = 1; i < sums.size(); ++i)
  {
    if (sums[i].first < smallestSum) 
    {
      smallestSum = sums[i].first;
      smallestIdx = i;
      smallest = sums[i];
    }
  }
  return smallest;
}

bool isEnd(Node node, int N)
{
  pair<int, int> indices = node.second;

  if (indices.first == N - 1 && indices.second == N - 1)
    return true;

  return false;
}

Node* getAdjacentX(Node root, vector<vector<int> > matrix)
{
  int x = root.second.first;
  int y = root.second.second;

  if (x + 1 == matrix.size())
    return NULL;
  
  Node *adjx = new Node(root.first + matrix[x+1][y], pair<int, int>(x+1, y));

  return adjx;
} 

Node* getAdjacentY(Node root, vector<vector<int> > matrix)
{
  int x = root.second.first;
  int y = root.second.second;

  if (y + 1 == matrix.size())
    return NULL;
  
  Node *adjy = new Node(root.first + matrix[x][y+1], pair<int, int>(x, y+1));

  return adjy;
}
