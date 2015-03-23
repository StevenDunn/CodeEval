// array absurdity soln in c for code eval by steven a dunn

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
int contains(Array*, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, ";");
            token = strtok(NULL, ";");

            Array nums;
            init(&nums, 1);

            char* vals = token;
            token = strtok(vals, ",");
            while (token != NULL)
            {
                int x = atoi(token);
                if (contains(&nums, x))
                {
                    printf("%d\n", x);
                    break;
                }
                insert(&nums, x);
                token = strtok(NULL, ",");
            }
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

int contains(Array* arr, int element)
{
    for(int i = 0; i < arr->used; ++i)
        if (arr->array[i] == element)
            return 1;
    return 0;
}