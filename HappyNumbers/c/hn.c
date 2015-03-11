// happy numbers soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, int);
void clear(Array*);

int isHappy(int);

Array visited;

int main(int argc, char* argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            init(&visited, 1);
            int n = atoi(line);
            if (isHappy(n))
                printf("1\n");
            else
                printf("0\n");
            clear(&visited);
        }
        fclose(fp);
    }
    return 0;
}

int isHappy(int n)
{
    int sum = 0;
    int part = 0;

    while (n > 0)
    {
        part = (n % 10);
        sum += (part * part);
        n = (n/10);
    }

    if (sum == 1)
        return 1;

    for (int i = 0; i < visited.used; i++)
        if (i == sum)
            return 0;
    insert(&visited, sum);

    if (isHappy(sum))
        return 1;
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

void clear(Array* arr)
{
    free(arr->array);
    arr->array = 0;
    arr->size = 0;
    arr->used = 0;
}