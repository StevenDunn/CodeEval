// even numbers soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[8];
        while (fgets(line, sizeof(line), fp))
        {
            int x = atoi(line);
            if (x % 2)
                puts("0");
            else
                puts("1");
        }
        fclose(fp);
    }
    return 0;
}