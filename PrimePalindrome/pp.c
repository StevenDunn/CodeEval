// prime palindrome soln in c for codeeval by steven a dunn

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int isPrime(int);
int isPalindrome(int);

int main(int argc, char* argv[])
{
    int pal_idx;
    for(pal_idx = 1000; pal_idx > 9; pal_idx--)
    {
        if(isPrime(pal_idx) && isPalindrome(pal_idx))
        {
            printf("%d\n",pal_idx);
            break;
        }
    }
    return 0;
}

int isPrime(int n)
{
    if (n % 2 == 0) { return FALSE; }

    for(int i = 3; i < n; i = i + 2)
        if (n % i == 0) { return FALSE; }

    return TRUE;
}

int isPalindrome(int n)
{
    char num_str[5];
    sprintf(num_str, "%d", n);

    const char *c1 = &num_str[0];
    const char *c2 = &num_str[strlen(num_str) - 1];

    while(c1 < c2)
    {
        if (*c1 != *c2) { return FALSE; }
        c1++;
        c2--;
    }
    return TRUE;
}
