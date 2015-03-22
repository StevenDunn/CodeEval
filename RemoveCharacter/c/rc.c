// remove characters soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

void trim(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);

            char* token = strtok(line, ",");
            char* str = token;
            token = strtok(NULL, ", ");
            char* chars = token;

            while(*chars)
            {
                char *c = str;
                while (*c)
                {
                    if (*c == *chars)
                        *c = '\n';
                    ++c;
                }
                ++chars;
            }
            while(*str)
            {
                if (*str != '\n')
                    printf("%c", *str);
                ++str;
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

void trim(char* line)
{
    char* c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
    }
}