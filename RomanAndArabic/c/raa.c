// roman and arabic c soln for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim (char*);
int convert(char*);
int roman_to_arabic(char);
int calculate(int*, char**, int);
int greater(char, char);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while(fgets(line, sizeof(line), fp))
        {
            trim(line);

            int len = strlen(line) / 2;
            int digits[len];
            char* pairs[len];

            for (int i = 0; i < strlen(line); i += 2)
            {
                char *pair = (char*)malloc(3 * sizeof(char));
                pair[0] = line[i];
                pair[1] = line[i+1];
                pair[2] = '\0';

                pairs[i/2] = pair;
                digits[i/2] = convert(pair);
            }
            printf("%d\n", calculate(digits, pairs, len));

            for (int i = 0; i < len; ++i)
                free(pairs[i]);
        }
        fclose(fp);
    }
    return 0;
}

void trim (char* line)
{
    char *c = line;
    while (*c)
    {
        if (*c == '\n')
            *c = '\0';
        ++c;
    }
}

int convert(char* pair)
{
    int a = pair[0] - '0';
    int r = roman_to_arabic(pair[1]);
    return a * r;
}

int roman_to_arabic(char num)
{
    int result = 0;
    if (num == 'I')
     result = 1;
    else if (num == 'V')
        result = 5;
    else if (num == 'X')
        result = 10;
    else if (num == 'L')
        result = 50;
    else if (num == 'C')
        result = 100;
    else if (num == 'D')
        result = 500;
    else if (num == 'M')
        result = 1000;
    return result;
}

int calculate(int* digits, char** pairs, int len)
{
    int total = 0;
    char prev_r = pairs[0][1];
    for (int i = 0; i < len; ++i)
    {
        if (i == len - 1)
        {
            total += digits[i];
            continue;
        }
        char curr_r = pairs[i][1];
        char next_r = pairs[i+1][1];

        if (greater(next_r, curr_r))
            total -= digits[i];
        else
            total += digits[i];
    }
    return total;
}

int greater(char x, char y)
{
    int a = roman_to_arabic(x);
    int b = roman_to_arabic(y);
    return a > b;
}