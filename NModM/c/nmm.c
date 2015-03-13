// N mod M soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char* token = strtok(line, ",");
            int n = atoi(token);
            token = strtok(NULL, ",");
            int m = atoi(token);

            printf("%d\n", n % m);
        }
        fclose(fp);
    }
    return 0;
}