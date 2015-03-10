// Fibonacci Series soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>

long fib(int);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while(fgets(line, sizeof(line), fp))
            printf("%ld\n", fib(atoi(line)));
        fclose(fp);
    }
    return 0;
}

long fib(int n)
{
    long buf1 = 1;
    long buf2 = 1;
    long temp = 0;

    if (n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    for (int fibIdx = 3; fibIdx <= n; fibIdx++)
    {
        temp = buf1;
        buf1 = buf2;
        buf2 = buf1 + temp;
    }
    return buf2;
}