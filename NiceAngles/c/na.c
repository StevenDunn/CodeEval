// nice angles soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            float angle = atof(line);
            int full_degree = floor(angle);
            float remaining_angle = angle - full_degree;
            int minutes = floor(remaining_angle * 60);
            int seconds = floor(((remaining_angle * 60) - minutes) * 60);
            printf("%d.%02d'%02d\"\n", full_degree, minutes, seconds);
        }
        fclose(fp);
    }
    return 0;
}