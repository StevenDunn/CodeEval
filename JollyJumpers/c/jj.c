// jolly jumpers soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t size;
    size_t used;
} Array;

void init(Array*, size_t);
void insert(Array*, int);
void sort(Array*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            Array nums;
            init(&nums, 2);

            char *token = strtok(line, " ");
            while (token != NULL)
            {
                insert(&nums, atoi(token));
                token = strtok(NULL, " ");
            }

            Array abs_diffs;
            init(&abs_diffs, 1);

            int not_jolly = 0;

            for (int i = 1; i < nums.array[0]; ++i)
                insert(&abs_diffs, abs(nums.array[i] - nums.array[i+1]));

            sort(&abs_diffs);

            for (int i = 0; i < nums.array[0] - 2; ++i)
                if (abs_diffs.array[i] == 0 || abs_diffs.array[i+1] > abs_diffs.array[i] + 1)
                {
                    not_jolly = 1;
                    break;
                }

            if (not_jolly)
                puts("Not jolly");
            else
                puts("Jolly");
        }
        fclose(fp);
    }
    return 0;
}

void init(Array *arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array *arr, int element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int*)realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

void sort(Array* arr)
{
    for (int i = 1; i < arr->used; ++i)
        for (int j = 0; j < i; ++j)
            if (arr->array[i] == arr->array[j])
            {
                int temp = arr->array[i];
                arr->array[i] = arr->array[j];
                arr->array[j] = temp;
            }
}