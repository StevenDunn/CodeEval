// data recovery soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_missing(int*, size_t);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            char* token = strtok(line, ";");
            char* text_token = token;

            token = strtok(NULL, ";");
            char* indices_token = token;

            char* text[128];
            token = strtok(text_token, " ");

            int i = 0;
            while (token != NULL)
            {
                text[i] = token;
                i++;
                token = strtok(NULL, " ");
            }
            int text_length = i;

            int indices[128];
            token = strtok(indices_token, " ");

            i = 0;
            while (token != NULL)
            {
                indices[i] = atoi(token);
                i++;
                token = strtok(NULL, " ");

            }
            int missing = find_missing(indices, text_length);
            indices[i] = missing;

            for (int i = 1; i <= text_length; ++i)
            {
                for (int j = 0; j < text_length; ++j)
                {
                    if (indices[j] == i)
                    {
                        printf("%s ", text[j]);
                        break;
                    }
                }
            }
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

int find_missing(int* indices, size_t text_length)
{
    int sum = 0;
    for (int i = 0; i < text_length - 1; ++i)
        sum += indices[i];

    int expected_sum = text_length * (text_length + 1) / 2;
    return expected_sum - sum;
}