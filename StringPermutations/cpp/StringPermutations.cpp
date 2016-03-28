// String Permutations solution in C++ for CodeEval.com

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::sort;
using std::string;
using std::vector;

void findPermutations(string, int);
void swap(string&, int, int);

vector<string> permutations;

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      findPermutations(line, 0);
      sort(permutations.begin(), permutations.end());
      
      for(int i = 0; i < permutations.size() - 1; ++i)
        cout << permutations[i] << ",";
      cout << permutations[permutations.size() - 1] << endl;

      permutations.clear(); 
    }
    inputFile.close();
  }

  return 0;
}

void findPermutations(string line, int idx)
{
  int i = 0;
  if (idx == line.size())
  {
    permutations.push_back(line);
    return;
  }
  for (int i = idx; i < line.size(); ++i)
  {
    swap(line, idx, i);
    findPermutations(line, idx + 1);
    swap(line, idx, i);
  }
}

void swap(string& line, int x, int y)
{
  char tmp = line[x];
  line[x] = line[y];
  line[y] = tmp; 
}
