// without repetitions soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char* c = line;
            printf("%c", c[0]);
            for (int i = 1; i < strlen(line); ++i)
            {
                if (c[i] != c[i-1])
                    printf("%c", c[i]);
            }
        }
        fclose(fp);
    }
    return 0;
}