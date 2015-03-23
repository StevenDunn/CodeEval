// pascals triangle soln in c for code eval by steven a dunn

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
void clear(Array*);
void copy(Array*, Array*);

void print_triangle(int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
            print_triangle(atoi(line));
        fclose(fp);
    }
    return 0;
}

void print_triangle(int depth)
{
    printf("1 ");

    Array previous_line;
    init(&previous_line, 1);
    insert(&previous_line, 1);

    Array this_line;
    init(&this_line, 1);
    for (int i = 2; i <= depth; ++i)
    {
        clear(&this_line);
        init(&this_line, 1);
        insert(&this_line, 1);
        printf("1 ");
        for (int j = 0; j < previous_line.used - 1; ++j)
        {
            int next_val = previous_line.array[j] + previous_line.array[j+1];
            insert(&this_line, next_val);
            printf("%d ", next_val);
        }
        insert(&this_line, 1);
        printf("1 ");
        copy(&previous_line, &this_line);
    }
    puts("");
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
    arr->used = 0;
    arr->size = 0;
}

void copy(Array* arr1, Array* arr2)
{
    arr1->array = realloc(arr1->array, arr2->size * sizeof(int));
    memcpy(arr1->array, arr2->array, arr2->size * sizeof(int));
    arr1->size = arr2->size;
    arr1->used = arr2->used;
}