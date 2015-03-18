// penultimate word soln in c for code eval by steven a dunn

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
            char *token, *prev, *next;
            prev = strtok(line, " ");
            token = strtok(NULL, " ");
            next = strtok(NULL, " ");
            while (next != NULL)
            {
                prev = token;
                token = next;
                next = strtok(NULL, " ");
            }
            puts(prev);
        }
        fclose(fp);
    }
    return 0;
}