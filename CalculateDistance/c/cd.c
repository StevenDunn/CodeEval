// calculate distance soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < sizeof(line); ++i)
            {
                if (line[i] == '(' || line[i] == ')')
                    line[i] = ' ';
                else if (line[i] == '\n')
                    line[i] = '\0';
            }

            int x1, y1, x2, y2;

            char* token = strtok(line, " ");
            x1 = atoi(token);

            token = strtok(NULL, " ");
            y1 = atoi(token);

            token = strtok(NULL, " ");
            x2 = atoi(token);

            token = strtok(NULL, " ");
            y2 = atoi(token);

            int distance = (int)sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            printf("%d\n", distance);
        }
        fclose(fp);
    }
    return 0;
}