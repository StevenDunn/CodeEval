// find a writer soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, "|");
            char* cipher = token;

            token = strtok(NULL, "|");
            char* code = token;

            token = strtok(code, " ");
            while (token != NULL)
            {
                int key = atoi(token) - 1;
                printf("%c", cipher[key]);
                token = strtok(NULL, " ");
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}