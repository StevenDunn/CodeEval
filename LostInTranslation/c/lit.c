// lost in translation c soln for code eval by steven a dunn

#include <stdio.h>

char cipher[] = { 'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q', ' '};

void trim(char*);
int find_index(char);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            trim(line);
            char *c = line;
            while (*c)
            {
                if (*c == ' ')
                    printf("%c", ' ');
                else
                    printf("%c", find_index(*c) + 'a');
                ++c;
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

void trim(char* line)
{
    char *c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
    }
}

int find_index(char c)
{
    for (int i = 0; i < 27; ++i)
        if (cipher[i] == c)
            return i;
    return -1;
}