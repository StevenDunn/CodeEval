// Predict the number solution in C for CodeEval.com by Steven A. Dunn

#include <stdio.h>
#include <stdlib.h>

long calculate(long);

int main (int argc, char* const argv[])
{
  FILE *fp = fopen(argv[1], "r");
  if (fp != NULL)
  {
    char line[256];
    while (fgets(line, sizeof(line), fp))
    {
      long n = atol(line);
      long x = calculate(n);
      int offset = 0;
      while (n > 0)
      {
        n -= x;
        offset++;
        x = calculate(n);
      }
      printf("%d\n", offset % 3);
    }
    fclose(fp);
  }
  return 0;
}

long calculate(long n)
{
  long x = 2;
  while (x <= n)
    x *= 2;
  return x/2;
}