// swap elements soln in c for code eval by stevan a dunn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

typedef struct {
    char **array;
    size_t used;
    size_t size;
} CharArray;


void init(Array*, size_t);
void insert(Array*, int);

void init_char(CharArray*, size_t);
void insert_char(CharArray*, char*);

int main(int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char* nums, *swaps;

            char* token = strtok(line, ":");
            nums = token;

            token = strtok(NULL, ":");
            swaps = token;

            Array num_arr;
            init(&num_arr, 1);

            token = strtok(nums, " ");
            while (token != NULL)
            {
                insert(&num_arr, atoi(token));
                token = strtok(NULL, " ");
            }

            CharArray swaps_arr;
            init_char(&swaps_arr, 1);

            token = strtok(swaps, ",");
            while (token != NULL)
            {
                insert_char(&swaps_arr, token);
                token = strtok(NULL, ",");
            }

            for (int i = 0; i < swaps_arr.used; ++i)
            {
                token = strtok(swaps_arr.array[i], "-");
                int x = atoi(token);

                token = strtok(NULL, "-");
                int y = atoi(token);

                int temp = num_arr.array[x];
                num_arr.array[x] = num_arr.array[y];
                num_arr.array[y] = temp;
            }

            for (int i = 0; i < num_arr.used; ++i)
                printf("%d ", num_arr.array[i]);
            puts("");

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

void init_char(CharArray* arr, size_t initSize)
{
    arr->array = (char**)malloc(initSize * sizeof(char*));
    arr->used = 0;
    arr->size = initSize;
}

void insert_char(CharArray* arr, char* element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (char**)realloc(arr->array, arr->size * sizeof(char*));
    }
    arr->array[arr->used++] = element;
}