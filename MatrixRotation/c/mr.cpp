// matrix rotation soln in c by steven a dunn for code eval

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = ' ';

            int len = ceil(strlen(line) / 2.0);
            char* matrix[len];

            int matrix_idx = 0;
            char* token = strtok(line, " ");
            while (token != NULL)
            {
                matrix[matrix_idx] = token;
                matrix_idx++;
                token = strtok(NULL, " ");
            }

            int n = (int)sqrt((float)len);
            char* result = (char*)malloc(len * sizeof(char*));
            strcpy(result, "");
            for (int j = 0; j < n; ++j)
                for (int i = n - 1; i > -1; i--)
                {
                    strcat(result, matrix[(i * n) + j]);
                    strcat(result, " ");
                }
            puts(result);
        }
        fclose(fp);
    }
    return 0;
}