// sudkoku soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, int);

char* is_valid(Array*, int);
int row_check(Array*, int);
int col_check(Array*, int);
int grid_check(Array*, int);
int get_sum_for_check(int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, ";");
            int N = atoi(token);

            token = strtok(NULL, ";");
            char *vals_str = token;

            Array vals;
            init(&vals, 1);

            token = strtok(vals_str, ",");
            while (token != NULL)
            {
                insert(&vals, atoi(token));
                token = strtok(NULL, ",");
            }

            puts(is_valid(&vals, N));
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, int element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

char* is_valid(Array* vals, int N)
{
    if (row_check(vals, N) && col_check(vals, N) && grid_check(vals, N))
        return "True";
    return "False";
}

int row_check(Array* vals, int N)
{
    int sum_for_check = get_sum_for_check(N);

    for (int i = 0; i < N * N; i += N)
    {
        int row_sum = 0;
        for (int j = 0; j < N; ++j)
            row_sum += vals->array[i + j];

        if (row_sum != sum_for_check)
            return 0;
    }
    return 1;
}

int col_check(Array* vals, int N)
{
    int sum_for_check = get_sum_for_check(N);

    for (int i = 0; i < N; ++i)
    {
        int col_sum = 0;
        for (int j = 0; j < N * N; j += N)
            col_sum += vals->array[i + j];

        if (col_sum != sum_for_check)
            return 0;
    }
    return 1;
}

int grid_check(Array* vals, int N)
{
    int sum_for_check = get_sum_for_check(N);
    int sqrt_n = sqrt(N);
    for (int grid_x = 0; grid_x < sqrt_n; ++grid_x)
    {
        for (int grid_y = 0; grid_y < sqrt_n; ++grid_y)
        {
            int grid_sum = 0;
            for (int i = 0; i < sqrt_n; ++i)
                for (int j = 0; j < sqrt_n; ++j)
                    grid_sum += vals->array[N * i + j + grid_y * (N * sqrt_n) + grid_x * (sqrt_n)];
            if (grid_sum != sum_for_check)
                return 0;
        }
    }
    return 1;
}

int get_sum_for_check(int N)
{
    int result;
    if (N == 4)
        result = 4 + 3 + 2 + 1;
    else
        result = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1;
    return result;
}