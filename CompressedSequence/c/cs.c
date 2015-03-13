// compressed sequence soln in c by steven a dunn for code eval

#include <stdio.h>
#include <string.h>

int main(int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[2048];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            char* token = strtok(line, " ");
            char* cur = token;
            int count = 0;
            while (token != NULL)
            {
                if (!strcmp(token, cur))
                    count++;
                else
                {
                    printf("%d %s ", count, cur);
                    cur = token;
                    count = 1;
                }
                token = strtok(NULL, " ");
            }
            printf("%d %s ", count, cur);
            puts("");
        }
        fclose(fp);
    }
    return 0;
}