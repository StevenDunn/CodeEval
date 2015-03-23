// counting primes soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_primes(int, int);
int is_prime(int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, ",");
            int m = atoi(token);

            token = strtok(NULL, ",");
            int n = atoi(token);

            printf("%d\n", count_primes(m, n));
        }
        fclose(fp);
    }
    return 0;
}

int count_primes(int m, int n)
{
    int count = 0;
    for (int i = m; i <= n; ++i)
        if (is_prime(i))
            ++count;
    return count;
}

int is_prime(int n)
{
    if (n == 2)
        return 1;
    else if (n % 2 ==  0)
        return 0;

    int root = sqrt(n);
    for (int i = 3; i <= root; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}