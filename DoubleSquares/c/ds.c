// double squares soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// max size is the sqrt of the max input divided by 2
#define MAX_SIZE 23170

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        short* cachedVals = (short*)calloc(MAX_SIZE, sizeof(short));
        char line[16];
        fgets(line, sizeof(line), fp); // throw line away
        while (fgets(line, sizeof(line), fp))
        {
            long n = atol(line);
            int count = 0;
            int upperLimit = sqrt(n/2);

            for (int i = 0; i <= upperLimit; ++i)
            {
                if (cachedVals[i] == 0)
                    cachedVals[i] = i;
                double j = sqrt((double)n - (cachedVals[i] * cachedVals[i]));
                if (j - (int)j == 0.0)
                    count += 1;
            }
            printf("%d\n", count);
        }
        free(cachedVals);
        fclose(fp);
    }
    return 0;
}