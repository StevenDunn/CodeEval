// Sum To Zero solution in C++ for CodeEval.com by Steven A. Dunn

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

int count;

vector<int> parseLine(string);
void countSums(vector<int> &numbers, int depth, int sum);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
    {
      count = 0;

      vector<int> numbers = parseLine(line);
      countSums(numbers, 4, 0);
      // 24 == 4! which allows us to trim the duplicate counts, since
      // we are only interested in the combinations, not the permutations
      cout << count/24 << endl;
    }
    inputFile.close();
  }

  return 0;
}

vector<int> parseLine(string line)
{
  replace(line.begin(), line.end(), ',', ' ');
  vector<int> result;
  istringstream iss(line);
  string s;
  while (iss >> s)
    result.push_back(atoi(s.c_str()));
  return result;
}

void countSums(vector<int> &numbers, int depth, int sum)
{
  if (depth == 0)
  {
    if (sum == 0)
      count++;
    return;
  }

  int updatedSum = 0;
  for (int i = 0; i < numbers.size(); ++i)
  {
    int num = numbers[i];
    updatedSum = sum + num;
    numbers.erase(numbers.begin() + i);

    countSums(numbers, depth - 1, updatedSum);
    numbers.insert(numbers.begin() + i, num);
  }
}
