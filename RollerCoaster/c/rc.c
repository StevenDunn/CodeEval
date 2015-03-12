// rollercoaster soln in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < strlen(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            int letter_case = TRUE;

            for (int i = 0; i < strlen(line); ++i)
            {
                char c = line[i];

                if (isalpha(c))
                {
                    if (letter_case)
                        c = (char)toupper(c);
                    else
                        c = (char)tolower(c);

                    printf("%c", c);

                    if (letter_case == TRUE)
                        letter_case = FALSE;
                    else
                        letter_case = TRUE;
                }
                else
                    printf("%c", c);
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}