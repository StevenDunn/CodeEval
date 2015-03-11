// Odd Numbers soln written in C for CodeEval.com by Steven A. Dunn

#include <stdio.h>

int main(int argc, char* argv[])
{
  for(int i = 1; i < 100; i=i+2)
    printf("%d\n", i);
  return 0;
}