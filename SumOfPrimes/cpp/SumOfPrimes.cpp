// Sum of Primes program written in C++ for CodeEval.com by Steven A. Dunn

#include <stdio.h>

bool isPrime(int);

int main(int argc, char* argv[])
{
  long primeSum = 2; 
  int num = 3;
  int primeCount = 2;

  while(primeCount <= 1000)
  {
    if(isPrime(num)) 
    {
      primeSum += num;
      primeCount++;
    }
    num = num + 2;
  }
  printf("%ld\n", primeSum);

  return 0;
}

bool isPrime(int n)
{
  if (n%2 == 0) 
  {
    return false; 
  } 

  // Assumes prime checks begin at 3 (i.e. it ignores the primacy of 1 and 2)
  for(int i = 3; i < n; i = i+2)
  {
    if (n%i == 0) { return false; }
  } 
  
  return true;
}