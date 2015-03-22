// number of ones soln in c for code eval by steven a dunn

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * int2bin(int i);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char* binary = int2bin(atoi(line));
            int ones_count = 0;
            while (*binary)
            {
                if (*binary == '1')
                    ++ones_count;
                ++binary;
            }
            printf("%d\n", ones_count);
        }
        fclose(fp);
    }
    return 0;
}

// grabbed off stack overflow
char* int2bin(int i)
{
    size_t bits = sizeof(int) * CHAR_BIT;

    char * str = malloc(bits + 1);
    if(!str) return NULL;
    str[bits] = 0;

    // type punning because signed shift is implementation-defined
    unsigned u = *(unsigned *)&i;
    for(; bits--; u >>= 1)
        str[bits] = u & 1 ? '1' : '0';

    return str;
}