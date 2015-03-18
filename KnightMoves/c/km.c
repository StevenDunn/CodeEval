// knight moves soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValid(int*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            int col = line[0];
            int row = atoi(&line[1]);

            int possible_moves[8][2] = {{col-2, row-1}, {col-2,row+1}, {col-1,row-2}, {col-1,row+2}, {col+1,row-2}, {col+1,row+2}, {col+2,row-1}, {col+2,row+1}};

            for (int i = 0; i < 8; ++i)
            {
                if (isValid(possible_moves[i]))
                    printf("%c%d ", (char)possible_moves[i][0], possible_moves[i][1]);
            }
            printf("\n");
        }
        fclose(fp);
    }
    return 0;
}

int isValid(int* i) {
    //printf("%d %d\n", i[0], i[1]);
    if (i[0] >= 'a' && i[0] <= 'h' && i[1] >= 1 && i[1] <= 8)
        return 1;
    return 0;
}