// overlapping rectangles soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_overlap(int, int, int, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, ",");
            int Ax1 = atoi(line);

            token = strtok(NULL, ",");
            int Ay1 = atoi(token);

            token = strtok(NULL, ",");
            int Ax2 = atoi(token);

            token = strtok(NULL, ",");
            int Ay2 = atoi(token);

            token = strtok(NULL, ",");
            int Bx1 = atoi(token);

            token = strtok(NULL, ",");
            int By1 = atoi(token);

            token = strtok(NULL, ",");
            int Bx2 = atoi(token);

            token = strtok(NULL, ",");
            int By2 = atoi(token);

            if(is_overlap(Ax1, Ax2, Bx1, Bx2) && is_overlap(Ay1, Ay2, By1, By2))
                puts("True");
            else
                puts("False");
        }
        fclose(fp);
    }
    return 0;
}

int is_overlap(int a1, int a2, int b1, int b2)
{
    if (a1 > a2)
    {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }

    if (b1 > b2)
    {
        int temp = b1;
        b1 = b2;
        b2 = temp;
    }

    int overlap = 0;
    for (int i = a1; i <= a2; ++i)
        if (i >= b1 && i <= b2)
            overlap = 1;
    return overlap;
}