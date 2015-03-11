// unique elements soln in c for code eval by steven a dunn

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
            char* token = strtok(line, ",");
            char* cur_unique_token = token;

            size_t length = strlen(token);
            if (token[length-1] == '\n')
                token[length-1] = '\0';

            printf("%s", token);

            while (token != NULL)
            {
                token = strtok(NULL, ",");

                if (token == NULL)
                    break;

                length = strlen(token);
                if (token[length-1] == '\n')
                    token[length-1] = '\0';

                if (strcmp(token, cur_unique_token))
                {
                    cur_unique_token = token;
                    printf(",%s", token);
                }
            }
            printf("\n");
        }
        fclose(fp);
    }
    return 0;
}