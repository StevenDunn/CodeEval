// lettercase percentage ratio in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            int upper_count = 0;
            int lower_count = 0;

            for (int i = 0; i < strlen(line); ++i)
            {
                char c = line[i];
                if (isupper(c))
                    upper_count++;
                else if (islower(c))
                    lower_count++;
            }

            int total_count = upper_count + lower_count;
            float upper_percent = ((float)upper_count / total_count) * 100.0;
            float lower_percent = ((float)lower_count / total_count) * 100.0;

            printf("lowercase: %.2f uppercase: %.2f \n", lower_percent, upper_percent);
        }
        fclose(fp);
    }
    return 0;
}