// bats challenge soln in c for code eval by steven a dunn

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* array;
    size_t size;
    size_t used;
} Array;

void init(Array*, size_t);
void insert(Array*, int);
void sort(Array*);

int too_close(int, Array*, int);

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            char *token = strtok(line, " ");
            int length = atoi(token) - 6;

            token = strtok(NULL, " ");
            int spacing = atoi(token);

            token = strtok(NULL, " ");
            token = strtok(NULL, " ");

            Array bats;
            init(&bats, 1);
            while (token != NULL)
            {
                insert(&bats, atoi(token));
                token = strtok(NULL, " ");
            }

            sort(&bats);

            int new_bats = 0;
            for (int spot = 6; spot < length + 1; spot++)
                if (!too_close(spot, &bats, spacing))
                {
                    new_bats++;
                    insert(&bats, spot);
                }
            printf("%d\n", new_bats);
        }
        fclose(fp);
    }
    return 0;
}

void init(Array* arr, size_t initSize)
{
    arr->array = (int*)malloc(initSize * sizeof(int));
    arr->size = initSize;
    arr->used = 0;
}

void insert(Array* arr, int element)
{
    if (arr->used == arr->size)
    {
        arr->size *= 2;
        arr->array = (int *)realloc(arr->array, arr->size * sizeof(int));
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

int too_close(int spot, Array* bats, int spacing)
{
    for (int i = 0; i < bats->used; ++i)
        if (abs(spot - bats->array[i]) < spacing)
            return 1;
    return 0;
}