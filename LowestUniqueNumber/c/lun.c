// lowest unique number soln in c for code eval by steven a dunn

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
void sort(Array*);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            Array num_arr, sort_arr;
            init(&num_arr, 1);
            init(&sort_arr, 1);

            char *token = strtok(line, " ");
            while (token != NULL)
            {
                insert(&num_arr, atoi(token));
                insert(&sort_arr, atoi(token));
                token = strtok(NULL, " ");
            }
            sort(&sort_arr);

            int result = 0;
            int count = 1;
            int lowestUnique = -1;
            if (sort_arr.used == 1)
                lowestUnique = num_arr.array[0];
            else
            {
                for (int i = 0; i < sort_arr.used; ++i)
                {
                    if (sort_arr.array[i] == sort_arr.array[i+1])
                        ++count;
                    else
                    {
                        if (count == 1)
                        {
                            lowestUnique = sort_arr.array[i];
                            for (int i = 0; i < num_arr.used; ++i)
                                if (num_arr.array[i] == lowestUnique)
                                    result = i + 1;
                            break;
                        }
                        count = 1;
                    }
                }
                if (lowestUnique == -1)
                    result = 0;
            }
            printf("%d\n", result);
        }
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

void sort(Array* arr)
{
    for (int i = 1; i < arr->used; ++i)
        for (int j = 0; j < i; ++j)
            if (arr->array[i] < arr->array[j])
            {
                int temp = arr->array[i];
                arr->array[i] = arr->array[j];
                arr->array[j] = temp;
            }
}