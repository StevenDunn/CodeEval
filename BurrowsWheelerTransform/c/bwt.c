// burrows wheeler transform soln in c for code eval by steven a dunn

#include <stdio.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            puts(line);
        }
        fclose(fp);
    }
    return 0;
}