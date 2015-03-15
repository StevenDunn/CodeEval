// mixed content soln in c for code eval by steven a dunn

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* const argv[])
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

            char words[512], nums[512];
            strcpy(words, "");
            strcpy(nums, "");
            int words_len = 0;
            int nums_len = 0;

            char* token = strtok(line, ",");
            while (token != NULL)
            {
                if (isalpha(token[0]))
                {
                    strcat(words, token);
                    strcat(words, ",");
                    words_len += strlen(token) + 1;
                }
                else
                {
                    strcat(nums, token);
                    strcat(nums, ",");
                    nums_len += strlen(token) + 1;
                }
                token = strtok(NULL, ",");
            }
            words[words_len-1] = '\0';
            nums[nums_len-1] = '\0';

            if (nums_len == 0)
                printf("%s\n", words);
            else if (words_len == 0)
                printf("%s\n", nums);
            else
                printf("%s|%s\n", words, nums);
        }
        fclose(fp);
    }
    return 0;
}