// reverse and add soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long reverse(long);
int get_num_digits(int);
int is_palindrome(long);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[128];
        while (fgets(line, sizeof(line), fp))
        {
            long n = atol(line);
            long reversed_n = 0;
            for (int iterations = 0; iterations < 100; ++iterations)
            {
                reversed_n = reverse(n);
                n += reversed_n;
                if (is_palindrome(n))
                {
                    printf("%d %ld\n", (iterations + 1), n);
                    break;
                }
            }
        }
        fclose(fp);
    }
    return 0;
}

long reverse(long n)
{
    int num_digits = get_num_digits(n);
    char str[num_digits];
    sprintf(str, "%ld", n);

    char *start = str;
    char *end = str+strlen(str)-1;

    while(start < end)
    {
        char temp = *end;
        *end = *start;
        *start = temp;
        ++start;
        --end;
    }
    return atol(str);
}

int get_num_digits(int n)
{
    int digits = 0;
    int mod = 1;
    while (n % mod != n)
    {
        mod *= 10;
        digits++;
    }
    return digits;
}

int is_palindrome(long n)
{
    int num_digits = get_num_digits(n);
    char str[num_digits];
    sprintf(str, "%ld", n);

    char *start = str;
    char *end = str+strlen(str)-1;

    while (start < end)
    {
        if (*start != *end)
            return 0;
        ++start;
        --end;
    }
    return 1;
}