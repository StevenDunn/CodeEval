// bit position c soln for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_binary(int, int, char*);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");

    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, ",");
            int n = atoi(token);

            token = strtok(NULL, ",");
            int p1 = atoi(token);

            token = strtok(NULL, ",");
            int p2 = atoi(token);

            char binary[32];
            convert_to_binary(n, 32, binary);

            if (binary[strlen(binary) - p1] == binary[strlen(binary) - p2])
                printf("true\n");
            else
                printf("false\n");
        }
        fclose(fp);
    }
    return 0;
}

void convert_to_binary(int value, int bitsCount, char* output)
{
    int i;
    output[bitsCount] = '\0';
    for (i = bitsCount - 1; i >= 0; --i, value >>= 1)
    {
        output[i] = (value & 1) + '0';
    }
}