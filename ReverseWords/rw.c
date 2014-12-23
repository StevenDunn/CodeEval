// reverse words soln in c for codeeval by steven a dunn

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while(fgets(line, sizeof(line), fp))
        {
            // strip newline
            char *pos;
            if ((pos = strchr(line, '\n')) != NULL)
                *pos = '\0';

            // tokenize string
            char *tokens[20];
            int idx = 0;
            char *token = strtok(line, " ");
            while (token)
            {
                tokens[idx] = token;
                token = strtok(NULL, " ");
                idx++;
            }

            // print reversed string
            for (int i = idx - 1; i >= 0; i--)
                printf("%s ", tokens[i]);
            printf("\n");
        }
    }
    fclose(fp);
    return 0;
}