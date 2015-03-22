// sum of integers soln in c for code eval by steven a dunn

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
int max_subarray(Array*);
int max(int, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            Array arr;
            init(&arr, 1);

            char* token = strtok(line, ",");
            while (token != NULL)
            {
                insert(&arr, atoi(token));
                token = strtok(NULL, ",");
            }
            printf("%d\n", max_subarray(&arr));
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

int max_subarray(Array* arr)
{
    int max_ending_here, max_so_far;
    max_ending_here = max_so_far = arr->array[0];
    for (int x = 1; x < arr->used; ++x)
    {
        max_ending_here = max(arr->array[x], max_ending_here + arr->array[x]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}