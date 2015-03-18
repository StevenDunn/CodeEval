// simple sorting soln in c for code eval by steven a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float *array;
    size_t used;
    size_t size;
} Array;

void init(Array*, size_t);
void insert(Array*, float);
void sort(Array*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[1024];
        while (fgets(line, sizeof(line), fp))
        {
            Array arr;
            init(&arr, 2);

            char* token = strtok(line, " ");
            while (token != NULL)
            {
                insert(&arr, atof(token));
                token = strtok(NULL, " ");
            }

            sort(&arr);

            for (int i = 0; i < arr.used; ++i)
                printf("%.3f ", arr.array[i]);
            puts("");
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (float*)malloc(initSize * sizeof(float));
    arr->used = 0;
    arr->size = initSize;
}

void insert(Array* arr, float element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (float*)realloc(arr->array, arr->size * sizeof(float));
    }
    arr->array[arr->used++] = element;
}

void sort(Array* arr)
{
    for (int i = 1; i < arr->used; ++i)
        for (int j = 0; j < i; ++j)
            if (arr->array[i] < arr->array[j])
            {
                float temp = arr->array[i];
                arr->array[i] = arr->array[j];
                arr->array[j] = temp;
            }
}