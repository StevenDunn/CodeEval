// sum of digits soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            int n = atoi(line);
            int part = 0;
            int sum = 0;

            while (n > 0)
            {
                part = (n % 10);
                sum += part;
                n /= 10;
            }
            printf("%d\n", sum);
        }
        fclose(fp);
    }
    return 0;
}