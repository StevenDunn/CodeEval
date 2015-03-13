// swap case soln in c by steven a dunn for code eval

#include <ctype.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while(fgets(line, sizeof(line), fp))
        {
            for(int i = 0; i < sizeof(line); ++i)
            {
                if (line[i] == '\n')
                    continue;
                else if (line[i] == '\0')
                    break;
                else if (isupper(line[i]))
                    printf("%c", tolower(line[i]));
                else if (islower(line[i]))
                    printf("%c", toupper(line[i]));
                else
                    printf("%c", line[i]);
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}