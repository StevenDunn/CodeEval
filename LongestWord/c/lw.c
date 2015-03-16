// longest word soln in c for code eval by steven a dunn

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
            for (int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            int len = -1;
            char* longest;
            char* token = strtok(line, " ");
            while (token != NULL)
            {
                int tok_len = strlen(token);
                if (tok_len > len)
                {
                    len = strlen(token);
                    longest = token;
                }
                token = strtok(NULL, " ");
            }
            puts(longest);
        }
        fclose(fp);
    }
    return 0;
}