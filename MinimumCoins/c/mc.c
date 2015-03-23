// minimum coins soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>

int min_coins(int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
            printf("%d\n", min_coins(atoi(line)));
        fclose(fp);
    }
    return 0;
}

int min_coins(int n)
{
    int count = 0;
    while (n >= 5)
    {
        n -= 5;
        ++count;
    }
    while (n >= 3)
    {
        n -= 3;
        ++count;
    }
    count += n;
    return count;
}