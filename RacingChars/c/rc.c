// racing chars soln in c for code eval by steven a dunn

#include <stdio.h>

int find(char[13], char);
char update_direction(int, int);

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char direction = '|';
        int prev = -1;
        char line[14];
        while(fgets(line, sizeof(line), fp))
        {
            int gate_index = find(line, '_');
            if (prev == -1)
                prev = gate_index;

            int checkpoint_index = find(line, 'C');
            if (checkpoint_index == -1)
            {
                direction = update_direction(prev, gate_index);
                line[gate_index] = direction;
                prev = gate_index;
            }
            else
            {
                direction = update_direction(prev, checkpoint_index);
                line[checkpoint_index] = direction;
                prev = checkpoint_index;
            }
            printf("%s", line);
        }
        fclose(fp);
    }
    return 0;
}

int find(char line[13], char val)
{
    for(int i = 0; i < 13; ++i)
        if (line[i] == val)
            return i;
    return -1;
}

char update_direction(int prev, int index)
{
    char direction;
    if (index < prev)
        direction = '/';
    else if (index == prev)
        direction = '|';
    else
        direction = '\\';
    return direction;
}