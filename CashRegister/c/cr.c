// cash register soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPES_OF_CHANGE 12

char* change_types[TYPES_OF_CHANGE];
int change_vals[TYPES_OF_CHANGE];

void create_change_arrays();
void get_change(int);
int calculate_change(int, int*, int);
void print_change(int*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            create_change_arrays();

            char* token = strtok(line, ";");
            double price = atof(token) * 100;

            token = strtok(NULL, ";");
            double cash = atof(token) * 100;

            get_change(ceil(cash - price));

        }
        fclose(fp);
    }
    return 0;
}

void create_change_arrays()
{
    change_types[0] = "ONE HUNDRED";
    change_vals[0] = 10000;

    change_types[1] = "FIFTY";
    change_vals[1] = 5000;

    change_types[2] = "TWENTY";
    change_vals[2] = 2000;

    change_types[3] = "TEN";
    change_vals[3] = 1000;

    change_types[4] = "FIVE";
    change_vals[4] = 500;

    change_types[5] = "TWO";
    change_vals[5] = 200;

    change_types[6] = "ONE";
    change_vals[6] = 100;

    change_types[7] = "HALF DOLLAR";
    change_vals[7] = 50;

    change_types[8] = "QUARTER";
    change_vals[8] = 25;

    change_types[9] = "DIME";
    change_vals[9] = 10;

    change_types[10] = "NICKEL";
    change_vals[10] = 5;

    change_types[11] = "PENNY";
    change_vals[11] = 1;
}

void get_change(int change)
{
    if (change < 0)
        puts("ERROR");
    else if (change == 0)
        puts("ZERO");
    else
    {
        int *change_types_used = (int*)calloc(TYPES_OF_CHANGE, sizeof(int));
        for (int i = 0; i < TYPES_OF_CHANGE; ++i)
            change = calculate_change(change, change_types_used, i);
        print_change(change_types_used);
        free(change_types_used);
    }
}

int calculate_change(int change, int* change_types_used, int idx)
{
    if (change - change_vals[idx] >= 0)
    {
        while (change - change_vals[idx] >= 0)
        {
            change -= change_vals[idx];
            change_types_used[idx]++;
        }
    }
    return change;
}

void print_change(int* change_types_used)
{
    int first_time = 1;
    for (int i = 0; i < TYPES_OF_CHANGE; ++i)
        if (change_types_used[i] > 0)
        {
            for (int j = 0; j < change_types_used[i]; ++j)
            {
                if (first_time)
                {
                    printf("%s", change_types[i]);
                    first_time = 0;
                }
                else
                    printf(",%s", change_types[i]);
            }
        }
    puts("");
}
