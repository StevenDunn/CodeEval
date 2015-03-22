// trailing string soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

void trim(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            if (!strlen(line))
                continue;
            char* token = strtok(line, ",");
            char* str = token;
            token = strtok(NULL, ",");
            char* end = token;

            char* match = strstr(str, end);
            if (match != NULL)
            {
                match += strlen(end);
                if(*match)
                    puts("0");
                else
                    puts("1");
            }
            else
                puts("0");
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