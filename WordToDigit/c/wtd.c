// word to digit soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

int convert(char*);

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

            char* token = strtok(line, ";");
            while (token != NULL)
            {
                printf("%d",convert(token));
                token = strtok(NULL, ";");
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

int convert(char* text)
{
    if (!strcmp(text, "zero"))
        return 0;
    else if (!strcmp(text, "one"))
        return 1;
    else if (!strcmp(text, "two"))
        return 2;
    else if (!strcmp(text, "three"))
        return 3;
    else if (!strcmp(text, "four"))
        return 4;
    else if (!strcmp(text, "five"))
        return 5;
    else if (!strcmp(text, "six"))
        return 6;
    else if (!strcmp(text, "seven"))
        return 7;
    else if (!strcmp(text, "eight"))
        return 8;
    else if (!strcmp(text, "nine"))
        return 9;
    else
        return -1;
}