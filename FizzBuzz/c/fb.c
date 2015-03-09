// fizz buzz solution in C for codeeval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        int x, y, n;
        x = y = n = 0;
        while(fscanf(fp, "%d %d %d", &x, &y, &n) != EOF)
        {
            char output[1000];
            strcpy(output, "");

            int i;
            for (i = 1; i < (n + 1); i++)
            {
                int x_mod = i % x;
                int y_mod = i % y;

                if (x_mod == 0 && y_mod == 0)
                    strcat(output, "FB");
                else if (x_mod == 0)
                    strcat(output, "F");
                else if (y_mod == 0)
                    strcat(output, "B");
                else
                {
                    char i_str[5];
                    sprintf(i_str, "%d", i);
                    strcat(output, i_str);
                }
                strcat(output, " ");
            }
            printf("%s\n", output);

            // clear output buffer for next string
            output[0] = 0;
        }
    }
    fclose(fp);
}