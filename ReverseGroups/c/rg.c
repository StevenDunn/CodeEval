// reverse groups soln in c for code eval by steven a dunn

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
            char* token = strtok(line, ";");
            token = strtok(NULL, ";");
            int k = atoi(token);

            Array vals;
            init(&vals, 1);
            token = strtok(line, ",");
            while (token != NULL)
            {
                insert(&vals, atoi(token));
                token = strtok(NULL, ",");
            }

            Array reversed;
            init(&reversed, 1);
            for (int i = 0; i < vals.used; i += k)
            {
                if (vals.used - i < k || vals.used - i == 1)
                {
                    for (int j = i; j < vals.used-1; ++j)
                        insert(&reversed, vals.array[j]);
                    insert(&reversed, vals.array[vals.used-1]);
                }
                else
                    for (int j = i+k-1; j >= i; --j)
                        insert(&reversed, vals.array[j]);
            }

            for (int i = 0; i < reversed.used-1; ++i)
                printf("%d,", reversed.array[i]);
            printf("%d\n", reversed.array[reversed.used-1]);
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