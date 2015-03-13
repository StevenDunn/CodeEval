// hex to decimal soln by steven a dunn for code eval

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
            printf("%ld\n", strtol(line, NULL, 16));
        fclose(fp);
    }
    return 0;
}