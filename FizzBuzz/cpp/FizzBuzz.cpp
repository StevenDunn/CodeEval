// Fizz Buzz program written in C++ for CodeEval.com by Steven A. Dunn

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ostringstream;
using std::string;
using std::stringstream;

string fizzBuzz(int a, int b, int n);

int main(int argc, char* argv[])
{
  ifstream inputFile(argv[1]);

  string result, line;
  stringstream ssline;

  int A, B, N = 0;

  if(inputFile)
  {
    while(getline(inputFile, line))
    {
      ssline << line;
      ssline >> A;
      ssline >> B;
      ssline >> N;
   
      result = fizzBuzz(A, B, N);
 
      ssline.clear();
      cout << result << endl;
    }   
  }
  inputFile.close();

  return 0;
}

string fizzBuzz(int a, int b, int n)
{
  string result;
  for(int i = 1; i <= n; i++)
  {
    if (i%a == 0 && i%b == 0) { result.append("FB"); }
    else if (i%a == 0) { result.append("F"); }
    else if (i%b == 0) { result.append("B"); }
    else 
    { 
      ostringstream oss;
      oss << i;
      result.append(oss.str());
      oss.flush(); 
    }
    result.append(" ");
  }

  int sz = result.size();  
  result.resize(sz-1);

  return result;
}