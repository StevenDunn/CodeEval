// multiples of a number soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            int x = 0;
            int n = 0;
            char *token = strtok(line, ",");
            x = atoi(token);
            while (token != NULL)
            {
                token = strtok(NULL, ",");
                if (token != NULL)
                    n = atoi(token);
            }

            int multiple = 2;
            int multipleN = n;
            while (x > multipleN)
            {
                multipleN = n * multiple;
                multiple += 1;
            }
            printf("%d\n", multipleN);
        }
        fclose(fp);
    }
    return 0;
}