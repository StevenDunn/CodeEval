// number pairs soln in c for code eval by steven a dunn

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

int main (int argc, char* const argv[])
{
    FILE *fp = fopen(argv[1], "r");
    if (fp != NULL)
    {
        char line[512];
        while (fgets(line, sizeof(line), fp))
        {
            Array numbers;
            init(&numbers, 1);

            char* token = strtok(line, ";");
            token = strtok(NULL, ";");

            int n = atoi(token);

            token = strtok(line, ",");
            while (token != NULL)
            {
                insert(&numbers, atoi(token));
                token = strtok(NULL, ",");
            }

            int first_match = 1;
            for (int i = 0; i < numbers.used-1; ++i)
                for (int j = i+1; j < numbers.used; ++j)
                {
                    if (numbers.array[i] + numbers.array[j] == n)
                    {
                        if (first_match)
                        {
                            printf("%d,%d", numbers.array[i], numbers.array[j]);
                            first_match = 0;
                        }
                        else
                            printf(";%d,%d", numbers.array[i], numbers.array[j]);
                    }
                }
            if (first_match)
                printf("NULL");
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