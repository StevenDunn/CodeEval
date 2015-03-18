// read more soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_length(char*);
int find_last_space(char*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[3005];
        while (fgets(line, sizeof(line), fp))
        {
            int line_length = get_length(line);
            //printf("%d\n", line_length);
            if (line_length > 55)
            {
                char* short_line = (char*)malloc(41);
                strncpy(short_line, line, 40);
                short_line[40] = '\0';
                int last_space = find_last_space(short_line);
                if (last_space != -1)
                    short_line[last_space] = '\0';
                printf("%s... <Read More>\n", short_line);
            }
            else if (line_length == -1)
                puts(line);
            else
                printf("%s", line);
        }
        fclose(fp);
    }
    return 0;
}

int get_length(char* line)
{
    char* c = line;
    int idx = 0;
    while (*c)
    {
        if (*c == '\n' || *c == '\0')
            break;
        c++;
        idx++;
    }
    return idx;
}

int find_last_space(char* line)
{
    char* c = line;
    int last_space = -1;
    int idx = 0;
    while (*c)
    {
        if (*c == ' ')
            last_space = idx;
        c++;
        idx++;
    }
    return last_space;
}