// capitalize words soln in c by steven a dunn for code eval

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            for(int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';
            char *token = strtok(line, " ");
            while (token != NULL)
            {
                token[0] = toupper(token[0]);
                printf("%s ", token);
                token = strtok(NULL, " ");
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}