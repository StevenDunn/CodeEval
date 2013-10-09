// Distinct Subsequences solution in C++ for CodeEval.com by Steven A. Dunn


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int printNumDS(string);
int findNumDS(string);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    while (getline(inputFile, line))
      cout << printNumDS(line) << endl;
    
    inputFile.close();
  }

  return 0;
}

int printNumDS(string line)
{
  int numDS = findNumDS(line);
  return numDS;
}

int findNumDS(string line)
{
  int commaPos = line.find(",");
  string seq = line.substr(0, commaPos);
  string sub = line.substr(commaPos + 1);

  vector<int> numDs(sub.size() + 1, 0);
  numDs[sub.size()] = 1;
  for (int i = seq.size() - 1; i >= 0; --i)
    for (int j = 0; j < sub.size(); ++j)
      numDs[j] += (seq[i] == sub[j]) * numDs[j+1];

  return numDs[0];
}
