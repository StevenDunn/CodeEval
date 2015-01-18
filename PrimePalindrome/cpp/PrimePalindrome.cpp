// Prime Palindrome program written in C++ for CodeEval.com by Steven A. Dunn

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

bool isPrime(int);
bool isPalindrome(int);

int main(int argc, char* argv[])
{
  // Assume single-digit numbers not palindromes
  for(int palIdx = 1000; palIdx > 9; palIdx--)
  {
    if(isPrime(palIdx)) 
    {
      if(isPalindrome(palIdx))
      {
        printf("%d\n",palIdx);
        break;
      }
    }
  }
  return 0;
}

bool isPrime(int n)
{
  if (n%2 == 0) { return false; } 

  for(int i = 3; i < n; i = i+2)
  {
    if (n%i == 0) { return false; }
  } 
  
  return true;
}

bool isPalindrome(int n)
{
  stringstream numStream;
  numStream << n;
  string numStr = numStream.str();

  const char *c1 = &numStr.c_str()[0];
  const char *c2 = &numStr.c_str()[numStr.length()-1];

  while(c1 < c2)
  {
    if (*c1 != *c2) { return false; }
    c1++;
    c2--;   
  }
  return true;
}