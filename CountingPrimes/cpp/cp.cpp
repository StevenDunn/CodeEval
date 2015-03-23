// Counting Primes solution in C++ for CodeEval.com by Steven A. Dunn

#include <algorithm>
#include <cmath>
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
int countPrimes(int, int);
bool isPrime(int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      vector<int> tokens = parseLine(line);
      int primeCount = countPrimes(tokens[0], tokens[1]); 
      cout << primeCount << endl;
    }
    inputFile.close();
  }
  return 0;
}

vector<int> parseLine(string line)
{
  vector<int> tokens;
  replace(line.begin(), line.end(), ',', ' ');
  string s;
  istringstream iss(line);
  while (iss >> s)
    tokens.push_back(atoi(s.c_str()));
  return tokens;
}

int countPrimes(int M, int N)
{
  int count = 0;
  for (int i = M; i <= N; ++i)
    if(isPrime(i))
      ++count;
  return count;
}

bool isPrime(int n)
{
  if (n == 2)
    return true;
  else if (n % 2 ==  0)
    return false;

  int root = sqrt(n);
  for (int i = 3; i <= root; ++i)
    if (n % i == 0)
      return false;
  return true;
}
