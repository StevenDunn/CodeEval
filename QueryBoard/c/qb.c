// query board soln in c for code eval by steven a dunn

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initializeBoard();
void parseCommand(char*, char*, char*);

int board[256][256];

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        initializeBoard();
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            char *token, *command, *param1, *param2;

            token = strtok(line, " ");
            command = token;

            token = strtok(NULL, " ");
            param1 = token;

            token = strtok(NULL, " ");
            param2 = token;

            parseCommand(command, param1, param2);
        }
        fclose(fp);
    }
    return 0;
}

void initializeBoard()
{
    for (int i = 0; i < 256; ++i)
        for(int j = 0; j < 256; ++j)
            board[i][j] = 0;
}


void parseCommand(char* command, char* p1, char* p2)
{
    int param1 = atoi(p1);
    int param2;
    if (p2 != NULL)
        param2 = atoi(p2);
    else
        param2 = 0;
    int sum = 0;


    if (!strcmp(command, "SetRow"))
    {
        for (int i = 0; i < 256; ++i)
            board[i][param1] = param2;
    }
    else if (!strcmp(command, "SetCol"))
    {
        for (int j = 0; j < 256; ++j)
            board[param1][j] = param2;
    }
    else if (!strcmp(command, "QueryRow"))
    {
        sum = 0;
        for (int i = 0; i < 256; ++i)
            sum += board[i][param1];
        printf("%d\n", sum);
    }
    else if (!strcmp(command, "QueryCol"))
    {
        sum = 0;
        for (int j = 0; j < 256; ++j)
            sum += board[param1][j];
        printf("%d\n", sum);
    }

}