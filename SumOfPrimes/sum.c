// sum of primes soln in c for codeeval by steven a dunn

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_prime(int);

int main(int argc, char* argv[])
{
    int prime_sum = 2;
    int num = 3;
    int prime_count = 1;
    while (prime_count < 1000)
    {
        if (is_prime(num))
        {
            prime_sum += num;
            prime_count += 1;
        }
        num = num + 2;
    }
    printf("%d\n", prime_sum);
    return 0;
}

int is_prime(int n)
{
    if (n % 2 == 0) { return FALSE; }

    for(int i = 3; i < n; i = i + 2)
        if (n % i == 0) { return FALSE; }

    return TRUE;
}