// self describing numbers soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int counts[10];

int isSelfDescribing(int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            int n = atoi(line);
            if (isSelfDescribing(n))
                puts("1");
            else
                puts("0");

            for (int i = 0; i < 10; ++i)
                counts[i] = 0;
        }
        fclose(fp);
    }
    return 0;
}

int isSelfDescribing(int number)
{
    const int ASCII_TO_INT_CONVERSION = 48;
    int digit = 0;
    int n = number;
    int len = 0;
    while (n > 0)
    {
        digit = (n % 10);
        counts[digit]++;
        n = (n/10);
        len++;
    }
    char numStr[len];
    sprintf(numStr, "%d", number);

    for (int i = 0; i < strlen(numStr); i++)
        if (numStr[i] - ASCII_TO_INT_CONVERSION != counts[i])
            return 0;
    return 1;
}