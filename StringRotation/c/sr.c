// string rotation soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
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

            char *token = strtok(line, ",");
            char *text = token;

            token = strtok(NULL, ",");
            char *rotation = token;

            char *doubled_text = (char*)malloc(strlen(text) * 2 * sizeof(char));
            strcpy(doubled_text, "");
            strcat(doubled_text, text);
            strcat(doubled_text, text);

            char *match = strstr(doubled_text, rotation);
            if (match)
                puts("True");
            else
                puts("False");
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