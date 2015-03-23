// prime numbers soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void write_primes(unsigned long);
int is_prime(unsigned long);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            unsigned long n = atol(line);
            write_primes(n);
        }
        fclose(fp);
    }
    return 0;
}

void write_primes(unsigned long n)
{
    if (n >= 2)
        printf("2");
    for (unsigned long i = 3; i < n; ++i)
        if (i % 2 != 0 && is_prime(i))
            printf(",%lu", i);
    puts("");
}

int is_prime(unsigned long n)
{
    unsigned long root = sqrt(n);
    for (unsigned long i = 3; i <= root; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}