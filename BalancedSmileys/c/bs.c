// balanced smileys soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* is_balanced(char*);
char* replace_smileys(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            puts(is_balanced(line));
        }
        fclose(fp);
    }
    return 0;
}

char* is_balanced(char* line)
{
    if (!strcmp(line, ""))
        return "YES";

    line = replace_smileys(line);

    int min = 0;
    int max = 0;
    for (int i = 0; i < strlen(line); ++i)
    {
        char c = line[i];
        if (c == '(')
        {
            ++min;
            ++max;
        }
        else if (c == ')')
        {
            --min;
            --max;
            if (max < 0)
                return "NO";
        }
        else if (c == '{')
            ++max;
        else if (c == '}')
            --min;
    }

    if (min <= 0 && 0 <= max)
        return "YES";
    return "NO";
}

char* replace_smileys(char* line)
{
    char* new_str = (char*)malloc(strlen(line) * sizeof(char));
    char* c = new_str;
    strcpy(new_str, "");
    for (int i = 0; i < strlen(line) - 1; ++i)
    {
        char sub[3];
        sub[0] = line[i];
        sub[1] = line[i+1];
        sub[2] = '\0';
        if (!strcmp(sub, ":)"))
        {
            *c = '}';
            ++i;
        }
        else if (!strcmp(sub, ":("))
        {
            *c = '{';
            ++i;
        }
        else
            *c = line[i];
        ++c;
    }
    return new_str;
}