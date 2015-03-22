// first non-repeating character soln in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void trim(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while(fgets(line, sizeof(line), fp))
        {
            trim(line);
            char* c = line;
            int *counts = (int*)calloc(sizeof(int), 26);
            while (*c)
            {
                counts[tolower(*c)-48]++;
                ++c;
            }
            c = line;
            while (*c)
            {
                if (counts[tolower(*c)-48] == 1)
                {
                    printf("%c\n", *c);
                    break;
                }
                ++c;
            }
        }
        fclose(fp);
    }
    return 0;
}

void trim(char* line)
{
    char* c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
    }
}