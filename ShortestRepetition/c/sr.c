// shortest repetition soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            for (int i = 0; i < sizeof(line); ++i)
                if (line[i] == '\n')
                    line[i] = '\0';

            char firstChar = line[0];
            int repIdx = 1;

            for(int i = 1; i < strlen(line); ++i)
            {
                if(line[i] == firstChar)
                    break;
                ++repIdx;
            }
            printf("%d\n", repIdx);
        }
        fclose(fp);
    }
    return 0;
}