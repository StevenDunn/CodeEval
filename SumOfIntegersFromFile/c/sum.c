// sum of integers from file soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        int sum = 0;
        char line[1024];
        while (fgets(line, sizeof(line), fp))
            sum += atoi(line);
        printf("%d\n", sum);
        fclose(fp);
    }
    return 0;
}