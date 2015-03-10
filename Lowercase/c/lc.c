// lowercase soln in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");

    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < strlen(line); ++i)
                line[i] = tolower(line[i]);
            printf("%s", line);
        }
        fclose(fp);
    }
    return 0;
}