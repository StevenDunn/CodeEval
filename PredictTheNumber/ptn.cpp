// Predict the number solution in C++ for CodeEval.com by Steven A. Dunn

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

vector<int> seq;

int getNumber(unsigned long);
void expand(vector<int>);
int update(int);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);
  string line;

  if (inputFile)
  {
    seq.push_back(0);
    seq.push_back(1);
    while (getline(inputFile, line))
    {
      //cout << line << endl;
      cout << getNumber(atol(line.c_str())) << endl;
    }
    inputFile.close();
  }
  return 0;
}

int getNumber(unsigned long n)
{
  cout << n << endl;
  if (n < seq.size())
    return seq[n];

  unsigned long chunk = seq.size();
  while (n > chunk)
  {
    chunk *= 2;
    expand(seq);
  }
  return seq[n];
}

void expand(vector<int> sequence)
{
  unsigned long seqLen = sequence.size();
  for(unsigned long i = 0; i < seqLen; ++i)
    seq.push_back(update(seq[i]));
}

int update(int n)
{
  if (n == 0 || n == 1)
    return ++n;
  if (n == 2)
    return 0;
  else
    return -1;
}
