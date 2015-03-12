// big digits soln in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBigDigits(char*);
void bigPrint(char, char**);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
            printBigDigits(line);
        fclose(fp);
    }
    return 0;
}

void printBigDigits(char* line)
{
    char* rows[5];
    size_t size = 1024;
    for (int i = 0; i < 5; ++i)
        rows[i] = (char*)malloc(size * sizeof(char));

    for (int i = 0; i < strlen(line); ++i)
        if (isdigit(line[i]))
            bigPrint(line[i], rows);

    for (int i = 0; i < 5; ++i)
        printf("%s\n", rows[i]);

    char spacer[100] = "";
    for (int i = 0; i < strlen(rows[0]); ++i)
        strcat(spacer, "-");
    puts(spacer);

}

void bigPrint(char digit, char** rows)
{
    int val = digit - '0';

    if (val == 1)
    {
        strcat(rows[0], "--*--");
        strcat(rows[1], "-**--");
        strcat(rows[2], "--*--");
        strcat(rows[3], "--*--");
        strcat(rows[4], "-***-");
    }
    else if (val == 2)
    {
        strcat(rows[0], "***--");
        strcat(rows[1], "---*-");
        strcat(rows[2], "-**--");
        strcat(rows[3], "*----");
        strcat(rows[4], "****-");
    }
    else if (val == 3)
    {
        strcat(rows[0], "***--");
        strcat(rows[1], "---*-");
        strcat(rows[2], "-**--");
        strcat(rows[3], "---*-");
        strcat(rows[4], "***--");
    }
    else if (val == 4)
    {
        strcat(rows[0], "-*---");
        strcat(rows[1], "*--*-");
        strcat(rows[2], "****-");
        strcat(rows[3], "---*-");
        strcat(rows[4], "---*-");
    }
    else if (val == 5)
    {
        strcat(rows[0], "****-");
        strcat(rows[1], "*----");
        strcat(rows[2], "***--");
        strcat(rows[3], "---*-");
        strcat(rows[4], "***--");
    }
    else if (val == 6)
    {
        strcat(rows[0], "-**--");
        strcat(rows[1], "*----");
        strcat(rows[2], "***--");
        strcat(rows[3], "*--*-");
        strcat(rows[4], "-**--");
    }
    else if (val == 7)
    {
        strcat(rows[0], "****-");
        strcat(rows[1], "---*-");
        strcat(rows[2], "--*--");
        strcat(rows[3], "-*---");
        strcat(rows[4], "-*---");
    }
    else if (val == 8)
    {
        strcat(rows[0], "-**--");
        strcat(rows[1], "*--*-");
        strcat(rows[2], "-**--");
        strcat(rows[3], "*--*-");
        strcat(rows[4], "-**--");
    }
    else if (val == 9)
    {
        strcat(rows[0], "-**--");
        strcat(rows[1], "*--*-");
        strcat(rows[2], "-***-");
        strcat(rows[3], "---*-");
        strcat(rows[4], "-**--");
    }
    else if (val == 0)
    {
        strcat(rows[0], "-**--");
        strcat(rows[1], "*--*-");
        strcat(rows[2], "*--*-");
        strcat(rows[3], "*--*-");
        strcat(rows[4], "-**--");
    }
}