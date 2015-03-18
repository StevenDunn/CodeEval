// armstrong numbers soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            int number = atoi(line);

            int numDigits = 0;
            int part = 0;

            int n = number;
            while (n > 0)
            {
                part = (n % 10);
                numDigits++;
                n = (n/10);
            }

            n = number;
            double sum = 0;
            while (n > 0)
            {
                part = (n % 10);
                sum += pow((double)part, (double)numDigits);
                n = (n/10);
            }
            if ((int)sum == number)
                puts("True");
            else
                puts("False");
        }
        fclose(fp);
    }
    return 0;
}